// Solve 2023-06-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[100001], seg[400001], lazy[400001];

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        seg[node] = e - s + 1 - seg[node];

        if (s != e) {
            lazy[node * 2] = 1 - lazy[node * 2];
            lazy[node * 2 + 1] = 1 - lazy[node * 2 + 1];
        }
        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] = 1 - lazy[node];
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node * 2, s, mid, qs, qe);
    seg_update(node * 2 + 1, mid + 1, e, qs, qe);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query(node * 2, s, mid, qs, qe);
    int right_val = seg_query(node * 2 + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int cmd, qs, qe;
        cin >> cmd >> qs >> qe;

        if (cmd == 0) {
            seg_update(1, 1, n, qs, qe);
        }
        else {
            cout << seg_query(1, 1, n, qs, qe) << '\n';
        }
    }

    return 0;
}
