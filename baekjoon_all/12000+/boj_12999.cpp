// Solve 2025-12-18

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
    int idx, s, e, s_bucket;

    Query(int idx, int s, int e, int s_bucket) : idx(idx), s(s), e(e), s_bucket(s_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (s_bucket != rhs.s_bucket) return s_bucket < rhs.s_bucket;
        if (e != rhs.e) return e < rhs.e;
        return s < rhs.s;
    }
};

int a[100001];
int cnt[200001];
int cnt_cnt[100001];
int ans[100001];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += 100000;
    }

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
    cnt_cnt[1]++;
    int mx_cnt = 1;

    for (auto [q_idx, s, e, s_bucket] : queries) {
        while (s < left) {
            left--;
            int v = a[left];
            cnt_cnt[cnt[v]]--;
            cnt[v]++;
            cnt_cnt[cnt[v]]++;
            mx_cnt = max(mx_cnt, cnt[v]);
        }

        while (right < e) {
            right++;
            int v = a[right];
            cnt_cnt[cnt[v]]--;
            cnt[v]++;
            cnt_cnt[cnt[v]]++;
            mx_cnt = max(mx_cnt, cnt[v]);
        }

        while (left < s) {
            int v = a[left];
            left++;
            cnt_cnt[cnt[v]]--;
            if (cnt_cnt[mx_cnt] == 0) mx_cnt--;
            cnt[v]--;
            cnt_cnt[cnt[v]]++;
        }

        while (e < right) {
            int v = a[right];
            right--;
            cnt_cnt[cnt[v]]--;
            if (cnt_cnt[mx_cnt] == 0) mx_cnt--;
            cnt[v]--;
            cnt_cnt[cnt[v]]++;
        }

        ans[q_idx] = mx_cnt;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
