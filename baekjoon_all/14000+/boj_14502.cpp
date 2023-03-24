// Solve 2023-02-03
// Update 2023-03-23

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
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, m, graph[8][8];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int dfs(const vector<pii> &v) {
    int res = 0;
    int dfs_graph[8][8];
    bool dfs_visited[8][8] = { false };

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            dfs_graph[row][col] = graph[row][col];
        }
    }
    for (auto a : v) {
        dfs_graph[a.first][a.second] = 1;
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (dfs_visited[row][col]) {
                continue;
            }
            dfs_visited[row][col] = true;
            if (dfs_graph[row][col] == 1) {
                continue;
            }

            stack<pii> stck;
            stck.push({ row, col });
            bool detect_virus = (dfs_graph[row][col] == 2 ? true : false);
            int area = 1;

            while (!stck.empty()) {
                pii now = stck.top();
                stck.pop();
                for (int i = 0; i < 4; i++) {
                    pii next = { now.first + dx[i], now.second + dy[i] };
                    if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) {
                        continue;
                    }
                    if (dfs_visited[next.first][next.second]) {
                        continue;
                    }
                    dfs_visited[next.first][next.second] = true;
                    if (dfs_graph[next.first][next.second] == 1) {
                        continue;
                    }
                    if (dfs_graph[next.first][next.second] == 2) {
                        detect_virus = true;
                    }
                    area++;
                    stck.push(next);
                }
            }

            if (!detect_virus) {
                res += area;
            }
        }
    }

    return res;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> graph[row][col];
        }
    }

    int ans = 0;
    int nm = n * m;
    vector<pii> vec;
    for (int i = 0; i < nm; i++) {
        if (graph[i / m][i % m] != 0) {
            continue;
        }
        vec.push_back({ i / m, i % m });
        for (int j = i + 1; j < nm; j++) {
            if (graph[j / m][j % m] != 0) {
                continue;
            }
            vec.push_back({ j / m, j % m });
            for (int k = j + 1; k < nm; k++) {
                if (graph[k / m][k % m] != 0) {
                    continue;
                }
                vec.push_back({ k / m, k % m });
                ans = max(ans, dfs(vec));
                vec.pop_back();
            }
            vec.pop_back();
        }
        vec.pop_back();
    }
    cout << ans << '\n';

    return 0;
}
