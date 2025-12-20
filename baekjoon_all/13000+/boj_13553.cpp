// Solve 2025-12-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Query{
    int i, l, r, l_bucket;

    Query(int i, int l, int r, int l_bucket) : i(i), l(l), r(r), l_bucket(l_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (l_bucket != rhs.l_bucket) return l_bucket < rhs.l_bucket;
        if (r != rhs.r) return r < rhs.r;
        return l < rhs.l;
    }
};

int a[100001];
ll fenwick[100001];
ll ans[100001];

void update_fenwick(int idx, int v) {
    while (idx < 100001) {
        fenwick[idx] += v;
        idx += (idx & -idx);
    }
}

ll get_from_fenwick(int idx) {
    ll ret = 0;

    while (idx >= 1) {
        ret += fenwick[idx];
        idx -= (idx & -idx);
    }

    return ret;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<Query> queries;

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(i, l, r, l / sqrt_n);
    }

    sort(queries.begin(), queries.end());
    int left = 1;
    int right = 1;
    ll cur = 0;
    update_fenwick(a[1], 1);

    for (auto [q_idx, l, r, l_bucket] : queries) {
        while (l < left) {
            left--;
            int v = a[left];
            cur += get_from_fenwick(min(100000, v + k)) - get_from_fenwick(max(0, v - k - 1));
            update_fenwick(v, 1);
        }

        while (right < r) {
            right++;
            int v = a[right];
            cur += get_from_fenwick(min(100000, v + k)) - get_from_fenwick(max(0, v - k - 1));
            update_fenwick(v, 1);
        }

        while (left < l) {
            int v = a[left];
            left++;
            update_fenwick(v, -1);
            cur -= get_from_fenwick(min(100000, v + k)) - get_from_fenwick(max(0, v - k - 1));
        }

        while (r < right) {
            int v = a[right];
            right--;
            update_fenwick(v, -1);
            cur -= get_from_fenwick(min(100000, v + k)) - get_from_fenwick(max(0, v - k - 1));
        }

        ans[q_idx] = cur;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
