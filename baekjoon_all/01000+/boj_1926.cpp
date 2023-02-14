// Solve 2023-02-14

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

const int MAX_N = 500;
int n, m, ans1, ans2, graph[MAX_N][MAX_N];
int drow[4] = { 0, 0, -1, 1 }, dcol[4] = { 1, -1, 0, 0 };

void bfs(int row, int col) {
    int res = 1;
    graph[row][col] = 0;
    queue<pii> bfs_q;
    bfs_q.push({ row, col });

    while (!bfs_q.empty()) {
        pii now = bfs_q.front();
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = now.first + drow[i];
            int next_col = now.second + dcol[i];;
            if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m || graph[next_row][next_col] == 0) {
                continue;
            }
            graph[next_row][next_col] = 0;
            bfs_q.push({ next_row, next_col });
            res++;
        }
    }

    ans1++;
    ans2 = max(ans2, res);
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> graph[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (graph[row][col] == 1) {
                bfs(row, col);
            }
        }
    }

    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}