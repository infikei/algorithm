// Solve 2023-02-19

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int r, c, ans;
string graph[20];
int visited[26];
int drow[4] = { 0, 0, 1, -1 };
int dcol[4] = { 1, -1, 0, 0 };

void dfs(int nrow, int ncol, int depth) {
    ans = max(ans, depth);

    for (int i = 0; i < 4; i++) {
        int nxrow = nrow + drow[i];
        int nxcol = ncol + dcol[i];

        if (nxrow < 0 || nxrow >= r || nxcol < 0 || nxcol >= c || visited[graph[nxrow][nxcol] - 'A']) continue;
        visited[graph[nxrow][nxcol] - 'A'] = true;
        dfs(nxrow, nxcol, depth + 1);
        visited[graph[nxrow][nxcol] - 'A'] = false;
    }
}

int main() {
    FASTIO;

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> graph[i];
    }

    visited[graph[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << '\n';

    return 0;
}