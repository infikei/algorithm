// Solve 2023-06-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll arr[1000001], seg[4000001], lazy[4000001];

ll seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_init(node * 2, s, mid);
    ll right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        seg[node] += lazy[node] * (e - s + 1);
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe, ll val) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] += val;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node * 2, s, mid, qs, qe, val);
    seg_update(node * 2 + 1, mid + 1, e, qs, qe, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node * 2, s, mid, qs, qe);
    ll right_val = seg_query(node * 2 + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    m += k;
    for (int i = 0; i < m; i++) {
        int cmd, qs, qe;
        cin >> cmd >> qs >> qe;

        if (cmd == 1) {
            ll val;
            cin >> val;
            seg_update(1, 1, n, qs, qe, val);
        }
        else {
            cout << seg_query(1, 1, n, qs, qe) << '\n';
        }
    }

    return 0;
}
