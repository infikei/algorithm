// Solve 2023-07-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Query{
    int s, e, s2, idx;
    Query(int ns = 0, int ne = 0, int ns2 = 0, int nidx = 0) : s(ns), e(ne), s2(ns2), idx(nidx) {}
    bool operator<(const Query &rhs) const {
        if (s2 != rhs.s2) return s2 > rhs.s2;
        if (e != rhs.e) return e > rhs.e;
        return s > rhs.s;
    }
};

ll arr[100001];
priority_queue<Query> query_pq;
ll ans[100000];
ll cnt[1000001], now_val;
int now_s, now_e;

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < t; i++) {
        int s, e;
        cin >> s >> e;
        query_pq.push({ s, e, s / sqrt_n, i });
    }

    now_s = now_e = 1;
    cnt[arr[1]]++;
    now_val = arr[1];

    for (int i = 0; i < t; i++) {
        auto query = query_pq.top();
        query_pq.pop();

        while (query.s < now_s) {
            now_s--;
            ll num = arr[now_s];
            now_val += ((cnt[num] << 1) + 1) * num;
            cnt[num]++;
        }

        while (now_e < query.e) {
            now_e++;
            ll num = arr[now_e];
            now_val += ((cnt[num] << 1) + 1) * num;
            cnt[num]++;
        }

        while (now_s < query.s) {
            ll num = arr[now_s];
            cnt[num]--;
            now_val -= ((cnt[num] << 1) + 1) * num;
            now_s++;
        }

        while (query.e < now_e) {
            ll num = arr[now_e];
            cnt[num]--;
            now_val -= ((cnt[num] << 1) + 1) * num;
            now_e--;
        }

        ans[query.idx] = now_val;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
