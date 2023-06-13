// Solve 2023-06-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int arr[100001];
pii seg[400001];

pii seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = { arr[s], s };

    int mid = (s + e) >> 1;
    pii left_val = seg_init(node * 2, s, mid);
    pii right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = min(left_val, right_val);
}

void seg_update(int node, int s, int e, int qidx) {
    if (qidx < s || e < qidx) return;
    if (s == e) {
        seg[node] = { arr[s], s };
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node * 2, s, mid, qidx);
    seg_update(node * 2 + 1, mid + 1, e, qidx);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
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
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int qidx, qval;
            cin >> qidx >> qval;
            arr[qidx] = qval;
            seg_update(1, 1, n, qidx);
        }
        else {
            cout << seg[1].second << '\n';
        }
    }

    return 0;
}
