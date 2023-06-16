// Solve 2023-06-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

struct Pair{
    ll a, b;
    Pair(ll na = 1, ll nb = 0) : a(na), b(nb) {}
    bool operator==(const Pair &rhs) const {
        return a == rhs.a && b == rhs.b;
    }
    bool operator!=(const Pair &rhs) const {
        return !((*this) == rhs);
    }
    Pair operator*(const Pair &rhs) const {
        return { a * rhs.a % MOD, (b * rhs.a % MOD + rhs.b) % MOD };
    }
    Pair& operator*=(const Pair &rhs) {
        (*this) = (*this) * rhs;
        return *this;
    }
};

ll arr[100001], seg[400001];
Pair lazy[400001];

ll seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_init(node * 2, s, mid);
    ll right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = (left_val + right_val) % MOD;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != Pair(1, 0)) {
        seg[node] *= lazy[node].a;
        seg[node] %= MOD;
        seg[node] += lazy[node].b * (e - s + 1) % MOD;
        seg[node] %= MOD;

        if (s != e) {
            lazy[node * 2] *= lazy[node];
            lazy[node * 2 + 1] *= lazy[node];
        }
        lazy[node] = { 1, 0 };
    }
}

void seg_update(int node, int s, int e, int qs, int qe, Pair val) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] *= val;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node * 2, s, mid, qs, qe, val);
    seg_update(node * 2 + 1, mid + 1, e, qs, qe, val);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
}

ll seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node * 2, s, mid, qs, qe);
    ll right_val = seg_query(node * 2 + 1, mid + 1, e, qs, qe);
    return (left_val + right_val) % MOD;
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
        int cmd, x, y;
        cin >> cmd >> x >> y;

        if (cmd == 1) {
            ll v;
            cin >> v;
            seg_update(1, 1, n, x, y, { 1, v });
        }
        else if (cmd == 2) {
            ll v;
            cin >> v;
            seg_update(1, 1, n, x, y, { v, 0 });
        }
        else if (cmd == 3) {
            ll v;
            cin >> v;
            seg_update(1, 1, n, x, y, { 0, v });
        }
        else {
            cout << seg_query(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}
