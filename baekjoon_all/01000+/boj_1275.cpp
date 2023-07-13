// Solve 2023-07-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll arr[100001], seg[400001];

ll seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_init(node << 1, s, mid);
    ll right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int qidx, ll qval) {
    if (s == e) {
        seg[node] = qval;
        return;
    }

    int mid = (s + e) >> 1;
    if (qidx <= mid) seg_update(node << 1, s, mid, qidx, qval);
    else seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
    seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

ll seg_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node << 1, s, mid, qs, qe);
    ll right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    for (int i = 0; i < q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y) swap(x, y);
        cout << seg_query(1, 1, n, x, y) << '\n';
        seg_update(1, 1, n, a, b);
    }

    return 0;
}
