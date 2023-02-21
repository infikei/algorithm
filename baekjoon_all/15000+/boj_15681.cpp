// Solve 2023-02-21

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 100000;
vector<int> edges[MAX_N + 1];
int dp[MAX_N + 1];

void count_subtree_nodes(int cur, int parent) {
    dp[cur] = 1;

    for (auto next : edges[cur]) {
        if (next != parent) {
            count_subtree_nodes(next, cur);
            dp[cur] += dp[next];
        }
    }
}

int main() {
    FASTIO;

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    count_subtree_nodes(r, -1);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << dp[u] << '\n';
    }

    return 0;
}