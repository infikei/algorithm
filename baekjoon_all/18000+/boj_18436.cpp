// Solve 2023-06-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[100001], seg[400001];

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s] & 1;

    int mid = (s + e) >> 1;
    int left_val = seg_init(node * 2, s, mid);
    int right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int qidx) {
    if (qidx < s || e < qidx) return;
    if (s == e) {
        seg[node] = arr[s] & 1;
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node * 2, s, mid, qidx);
    seg_update(node * 2 + 1, mid + 1, e, qidx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int seg_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query(node * 2, s, mid, qs, qe);
    int right_val = seg_query(node * 2 + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 1) {
            arr[a] = b;
            seg_update(1, 1, n, a);
        }
        else if (cmd == 2) {
            cout << (b - a + 1) - seg_query(1, 1, n, a, b) << '\n';
        }
        else {
            cout << seg_query(1, 1, n, a, b) << '\n';
        }
    }

    return 0;
}
