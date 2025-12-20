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

int color[300001];
int cnt[10001];
int cnt_cnt[300001];
int ans[10001];

int main() {
    FASTIO;

    int n, c;
    cin >> n >> c;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
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
    cnt[color[left]]++;
    cnt_cnt[1]++;
    int mx_cnt = 1;

    for (auto [q_idx, s, e, s_bucket] : queries) {
        while (s < left) {
            left--;
            int v = color[left];

            cnt_cnt[cnt[v]]--;
            cnt[v]++;
            cnt_cnt[cnt[v]]++;
            mx_cnt = max(mx_cnt, cnt[v]);
        }

        while (right < e) {
            right++;
            int v = color[right];

            cnt_cnt[cnt[v]]--;
            cnt[v]++;
            cnt_cnt[cnt[v]]++;
            mx_cnt = max(mx_cnt, cnt[v]);
        }

        while (left < s) {
            int v = color[left];
            left++;

            cnt_cnt[cnt[v]]--;
            cnt[v]--;
            cnt_cnt[cnt[v]]++;
            if (cnt_cnt[mx_cnt] == 0) mx_cnt--;
        }

        while (e < right) {
            int v = color[right];
            right--;

            cnt_cnt[cnt[v]]--;
            cnt[v]--;
            cnt_cnt[cnt[v]]++;
            if (cnt_cnt[mx_cnt] == 0) mx_cnt--;
        }

        if (mx_cnt > (e - s + 1) / 2) {
            for (int i = 1; i <= c; i++) {
                if (cnt[i] == mx_cnt) {
                    ans[q_idx] = i;
                    break;
                }
            }
        }
        else {
            ans[q_idx] = -1;
        }
    }

    for (int i = 1; i <= q; i++) {
        if (ans[i] == -1) {
            cout << "no" << '\n';
        }
        else {
            cout << "yes " << ans[i] << '\n';
        }
    }

    return 0;
}
