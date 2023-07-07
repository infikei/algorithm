// Solve 2023-07-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Query{
    int idx, s, e, s2;
    Query(int nidx = 0, int ns = 0, int ne = 0, int ns2 = 0) : idx(nidx), s(ns), e(ne), s2(ns2) {}
    bool operator<(const Query &rhs) const {
        if (s2 != rhs.s2) return s2 > rhs.s2;
        if (e != rhs.e) return e > rhs.e;
        return s > rhs.s;
    }
};

int n, sqrt_n, m;
int arr[100001];
priority_queue<Query> query_pq;
int cnt[100001], cnt_cnt[100001], now_s, now_e, now_max_cnt;
int ans[100001];

int main() {
    FASTIO;

    cin >> n;
    sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        query_pq.push({ i, s, e, s / sqrt_n });
    }

    now_s = now_e = 1;
    cnt[arr[1]]++;
    cnt_cnt[1]++;
    now_max_cnt = 1;

    for (int i = 0; i < m; i++) {
        auto query = query_pq.top();
        query_pq.pop();

        while (query.s < now_s) {
            now_s--;
            int x = arr[now_s];
            cnt_cnt[cnt[x]]--;
            cnt[x]++;
            cnt_cnt[cnt[x]]++;
            now_max_cnt = max(now_max_cnt, cnt[x]);
        }

        while (now_e < query.e) {
            now_e++;
            int x = arr[now_e];
            cnt_cnt[cnt[x]]--;
            cnt[x]++;
            cnt_cnt[cnt[x]]++;
            now_max_cnt = max(now_max_cnt, cnt[x]);
        }

        while (now_s < query.s) {
            int x = arr[now_s];
            cnt_cnt[cnt[x]]--;
            if (now_max_cnt == cnt[x] && cnt_cnt[cnt[x]] == 0) now_max_cnt--;
            cnt[x]--;
            cnt_cnt[cnt[x]]++;
            now_s++;
        }

        while (query.e < now_e) {
            int x = arr[now_e];
            cnt_cnt[cnt[x]]--;
            if (now_max_cnt == cnt[x] && cnt_cnt[cnt[x]] == 0) now_max_cnt--;
            cnt[x]--;
            cnt_cnt[cnt[x]]++;
            now_e--;
        }

        ans[query.idx] = now_max_cnt;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
