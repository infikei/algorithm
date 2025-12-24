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
    int i, l, r, l_bucket;

    Query(int i, int l, int r, int l_bucket) : i(i), l(l), r(r), l_bucket(l_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (l_bucket != rhs.l_bucket) return l_bucket < rhs.l_bucket;
        if (r != rhs.r) return r < rhs.r;
        return l < rhs.l;
    }
};

int a[50001];
int cnt[50001];
int ans[50001];

int add_to_range(ll v) {
    if (v < 2 || v > 50000) return 0;

    cnt[v]++;

    if (cnt[v] == v) {
        cnt[v] = 0;
        return add_to_range(v * v) + 1;
    }

    return 0;
}

int remove_from_range(ll v) {
    if (v < 2 || v > 50000) return 0;

    cnt[v]--;

    if (cnt[v] == -1) {
        cnt[v] += v;
        return remove_from_range(v * v) + 1;
    }

    return 0;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cout << "Case #" << ti << '\n';

        int n;
        cin >> n;
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
        int cur = add_to_range(a[1]);

        for (auto [q_idx, l, r, l_bucket] : queries) {
            while (l < left) {
                left--;
                int v = a[left];
                cur += add_to_range(v);
            }

            while (right < r) {
                right++;
                int v = a[right];
                cur += add_to_range(v);
            }

            while (left < l) {
                int v = a[left];
                left++;
                cur -= remove_from_range(v);
            }

            while (r < right) {
                int v = a[right];
                right--;
                cur -= remove_from_range(v);
            }

            ans[q_idx] = cur;
        }

        for (int i = 1; i <= q; i++) {
            cout << ans[i] << '\n';
        }

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}
