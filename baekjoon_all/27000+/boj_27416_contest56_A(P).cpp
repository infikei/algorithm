// Solve 2023-07-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Query{
    int s, e, idx;
    Query(int ns = 0, int ne = 0, int nidx = 0) : s(ns), e(ne), idx(nidx) {}
    bool operator<(const Query &rhs) const {
        if (s != rhs.s) return s > rhs.s;
        if (e != rhs.e) return e > rhs.e;
        return idx > rhs.idx;
    }
};

priority_queue<Query> pq;
int ans[1000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        pq.push({ s, e, i });
    }

    int d = 1;
    while (d <= 31 && !pq.empty()) {
        if (d < pq.top().s) {
            d = pq.top().s;
        }

        int cnt = 0;
        while (cnt < k && !pq.empty() && d == pq.top().s) {
            cnt++;
            ans[pq.top().idx] = d;
            pq.pop();
        }

        while (!pq.empty() && d == pq.top().s) {
            auto a = pq.top();
            pq.pop();
            a.s++;
            pq.push(a);
        }

        d++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
