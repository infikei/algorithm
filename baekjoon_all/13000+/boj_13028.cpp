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

int a[100001];
int cnt[100001];
int ans[100001];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
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
    cnt[a[1]]++;
    int cur = 0;

    for (auto [q_idx, l, r, l_bucket] : queries) {
        while (l < left) {
            left--;
            int v = a[left];

            cnt[v]++;
            if (cnt[v] == 3) cur++;
        }

        while (right < r) {
            right++;
            int v = a[right];

            cnt[v]++;
            if (cnt[v] == 3) cur++;
        }

        while (left < l) {
            int v = a[left];
            left++;

            cnt[v]--;
            if (cnt[v] == 2) cur--;
        }

        while (r < right) {
            int v = a[right];
            right--;

            cnt[v]--;
            if (cnt[v] == 2) cur--;
        }

        ans[q_idx] = cur;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
