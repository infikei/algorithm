// Solve 2022-09-27
// Update 2023-12-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    int n;
    cin >> n;

    vector<string> board(n, "");

    for (string &row : board) {
        cin >> row;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> ans_vec;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] != '1' || visited[x][y]) continue;

            visited[x][y] = true;
            queue<Point> bfs_que;
            bfs_que.emplace(x, y);
            int val = 1;

            while (!bfs_que.empty()) {
                Point now = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = now.x + dx[d];
                    int ny = now.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != '1' || visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                    val++;
                }
            }

            ans_vec.push_back(val);
        }
    }

    sort(ans_vec.begin(), ans_vec.end());

    cout << SIZE(ans_vec) << '\n';

    for (int ans : ans_vec) {
        cout << ans << '\n';
    }

    return 0;
}
