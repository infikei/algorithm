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
    int i, s, e, s_bucket;

    Query(int i, int s, int e, int s_bucket) : i(i), s(s), e(e), s_bucket(s_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (s_bucket != rhs.s_bucket) return s_bucket < rhs.s_bucket;
        if (e != rhs.e) return e < rhs.e;
        return s < rhs.s;
    }
};

int a[1000001];
unordered_map<int, int> hs;
int cnt[1000001];
int ans[1000001];

int main() {
    FASTIO;

    int n;
    cin >> n;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;

        if (hs[v] == 0) {
            hs[v] = size(hs) + 1;
        }

        a[i] = hs[v];
    }

    int q;
    cin >> q;
    vector<Query> queries;

    for (int i = 1; i <= q; i++) {
        int s, e;
        cin >> s >> e;
        queries.emplace_back(i, s, e, s / sqrt_n);
    }

    sort(queries.begin(), queries.end());
    int left = 1;
    int right = 1;
    cnt[a[1]]++;
    int cur = 1;

    for (auto [q_idx, s, e, s_bucket] : queries) {
        while (s < left) {
            left--;
            int v = a[left];

            cnt[v]++;
            if (cnt[v] == 1) cur++;
        }

        while (right < e) {
            right++;
            int v = a[right];

            cnt[v]++;
            if (cnt[v] == 1) cur++;
        }

        while (left < s) {
            int v = a[left];
            left++;

            cnt[v]--;
            if (cnt[v] == 0) cur--;
        }

        while (e < right) {
            int v = a[right];
            right--;

            cnt[v]--;
            if (cnt[v] == 0) cur--;
        }

        ans[q_idx] = cur;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
