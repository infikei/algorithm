// Solve 2023-06-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[500000], seg[2000000], lazy[2000000];

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    int left_val = seg_init(node * 2 + 1, s, mid);
    int right_val = seg_init(node * 2 + 2, mid + 1, e);
    return seg[node] = left_val ^ right_val;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        if ((e - s) % 2 == 0) {
            seg[node] ^= lazy[node];
        }

        if (s != e) {
            lazy[node * 2 + 1] ^= lazy[node];
            lazy[node * 2 + 2] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe, int qval) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] ^= qval;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node * 2 + 1, s, mid, qs, qe, qval);
    seg_update(node * 2 + 2, mid + 1, e, qs, qe, qval);
    seg[node] = seg[node * 2 + 1] ^ seg[node * 2 + 2];
}

int seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query(node * 2 + 1, s, mid, qs, qe);
    int right_val = seg_query(node * 2 + 2, mid + 1, e, qs, qe);
    return left_val ^ right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    seg_init(0, 0, n - 1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd, qs, qe;
        cin >> cmd >> qs >> qe;

        if (cmd == 1) {
            int qval;
            cin >> qval;
            seg_update(0, 0, n - 1, qs, qe, qval);
        }
        else {
            cout << seg_query(0, 0, n - 1, qs, qe) << '\n';
        }
    }

    return 0;
}
