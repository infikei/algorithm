// Solve 2023-12-17

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

int solution(vector<vector<int>> land) {
    int dr[4] = { 0, 0, -1, 1 };
    int dc[4] = { -1, 1, 0, 0 };
    int n = land.size();
    int m = land[0].size();
    vector<int> dp(m + 1, 0);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || land[i][j] == 0) continue;

            visited[i][j] = true;
            int area = 1;
            int min_c = j;
            int max_c = j;
            queue<Point> bfs_que;
            bfs_que.emplace(i, j);

            while (!bfs_que.empty()) {
                Point now = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = now.r + dr[d];
                    int nc = now.c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (visited[nr][nc] || land[nr][nc] == 0) continue;

                    visited[nr][nc] = true;
                    area++;
                    min_c = min(min_c, nc);
                    max_c = max(max_c, nc);
                    bfs_que.emplace(nr, nc);
                }
            }

            dp[min_c] += area;
            dp[max_c + 1] -= area;
        }
    }

    int answer = dp[0];

    for (int j = 1; j < m; j++) {
        dp[j] += dp[j - 1];
        answer = max(answer, dp[j]);
    }

    return answer;
}
