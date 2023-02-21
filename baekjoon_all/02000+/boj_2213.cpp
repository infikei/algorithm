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

const int MAX_N = 10000;
int n;
int w[MAX_N + 1];
vector<int> adj[MAX_N + 1];
int dp[MAX_N + 1][2];
vector<int> ans2;

void dfs(int cur, int parent) {
    dp[cur][1] = w[cur];

    for (auto next : adj[cur]) {
        if (next != parent) {
            dfs(next, cur);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }
    }
}

void trace(int cur, int parent, int excluded) {
    if (excluded == 0 && dp[cur][1] > dp[cur][0]) {
        ans2.push_back(cur);
        for (auto next : adj[cur]) {
            if (next != parent) {
                trace(next, cur, 1);
            }
        }
    }
    else {
        for (auto next : adj[cur]) {
            if (next != parent) {
                trace(next, cur, 0);
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    dfs(1, -1);

    int ans = dp[1][0];
    int root_excluded = 1;
    if (dp[1][1] > dp[1][0]) {
        ans = dp[1][1];
        root_excluded = 0;
    }

    trace(1, -1, root_excluded);
    sort(ALL(ans2));

    cout << ans << '\n';
    for (auto a : ans2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}