// Solve 2023-07-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll arr[100001];
ll seg[400001], lazy[400001];

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        seg[node] += lazy[node] * (e - s + 1);

        if (s != e) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
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
        lazy[node] += qval;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node << 1, s, mid, qs, qe, qval);
    seg_update((node << 1) + 1, mid + 1, e, qs, qe, qval);
    seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

ll seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node << 1, s, mid, qs, qe);
    ll right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int qs, qe;
            cin >> qs >> qe;

            seg_update(1, 1, n, qs, qe, 1);
            if (qe < n) seg_update(1, 1, n, qe + 1, qe + 1, -(qe - qs + 1));
        }
        else {
            int qidx;
            cin >> qidx;

            cout << arr[qidx] + seg_query(1, 1, n, 1, qidx) << '\n';
        }
    }

    return 0;
}
