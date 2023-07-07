// Solve 2023-07-04
// Update 2023-07-06

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
int cnt[1000001], now_s, now_e, now_cnt;
int ans[100000];

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

    now_s = now_e = now_cnt = 1;
    cnt[arr[1]]++;

    for (int i = 0; i < m; i++) {
        auto query = query_pq.top();
        query_pq.pop();

        while (query.s < now_s) {
            now_s--;
            cnt[arr[now_s]]++;
            if (cnt[arr[now_s]] == 1) now_cnt++;
        }

        while (now_e < query.e) {
            now_e++;
            cnt[arr[now_e]]++;
            if (cnt[arr[now_e]] == 1) now_cnt++;
        }

        while (now_s < query.s) {
            cnt[arr[now_s]]--;
            if (cnt[arr[now_s]] == 0) now_cnt--;
            now_s++;
        }

        while (query.e < now_e) {
            cnt[arr[now_e]]--;
            if (cnt[arr[now_e]] == 0) now_cnt--;
            now_e--;
        }

        ans[query.idx] = now_cnt;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
