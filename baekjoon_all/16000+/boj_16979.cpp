// Solve 2025-12-21

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
    int i, s, e, s_bucket;

    Query(int i, int s, int e, int s_bucket) : i(i), s(s), e(e), s_bucket(s_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (s_bucket != rhs.s_bucket) return s_bucket < rhs.s_bucket;
        if (e != rhs.e) return e < rhs.e;
        return s < rhs.s;
    }
};

int a[100001];
vector<int> tmp;
int fenwick[100001];
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

    int n, q;
    cin >> n >> q;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }

    sort(tmp.begin(), tmp.end());
    UNIQUE(tmp);

    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
        a[i] = idx + 1;
    }

    vector<Query> queries;

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(i, l, r, l / sqrt_n);
    }

    sort(queries.begin(), queries.end());
    int left = 1;
    int right = 1;
    update_fenwick(a[1], 1);
    ll cur = 0;

    for (auto [q_idx, l, r, l_bucket] : queries) {
        while (l < left) {
            left--;
            int v = a[left];

            cur += get_from_fenwick(v - 1);
            update_fenwick(v, 1);
        }

        while (right < r) {
            right++;
            int v = a[right];

            cur += get_from_fenwick(100000) - get_from_fenwick(v);
            update_fenwick(v, 1);
        }

        while (left < l) {
            int v = a[left];
            left++;

            update_fenwick(v, -1);
            cur -= get_from_fenwick(v - 1);
        }

        while (r < right) {
            int v = a[right];
            right--;

            update_fenwick(v, -1);
            cur -= get_from_fenwick(100000) - get_from_fenwick(v);
        }

        ans[q_idx] = cur;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
