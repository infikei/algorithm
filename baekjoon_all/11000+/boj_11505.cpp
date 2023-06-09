// Solve 2022-12-09
// Update 2023-06-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;
ll arr[1000001], seg[4000001];

ll seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_init(node * 2, s, mid);
    ll right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = left_val * right_val % MOD;
}

ll seg_query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 1;
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node * 2, s, mid, l, r);
    ll right_val = seg_query(node * 2 + 1, mid + 1, e, l, r);
    return left_val * right_val % MOD;
}

void seg_update(int node, int s, int e, int idx) {
    if (idx < s || e < idx) return;
    if (s == e) {
        seg[node] = arr[s];
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node * 2, s, mid, idx);
    seg_update(node * 2 + 1, mid + 1, e, idx);
    seg[node] = seg[node * 2] * seg[node * 2 + 1] % MOD;
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
        int cmd, b, c;
        cin >> cmd >> b >> c;

        if (cmd == 1) {
            arr[b] = c;
            seg_update(1, 1, n, b);
        }
        else {
            cout << seg_query(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}
