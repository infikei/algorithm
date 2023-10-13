// Solve 2023-10-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

int main() {
    FASTIO;

    int dr[4] = { 0, 0, -1, 1 };
    int dc[4] = { -1, 1, 0, 0 };

    int n, m;
    cin >> n >> m;

    vector<string> board(n, "");
    queue<Point> que;

    for (int row = 0; row < n; row++) {
        cin >> board[row];

        for (int col = 0; col < m; col++) {
            if (board[row][col] == 'I') {
                que.emplace(row, col);
            }
        }
    }

    int cnt = 0;

    while (!que.empty()) {
        Point now = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nr = now.r + dr[d];
            int nc = now.c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            if (board[nr][nc] == 'O') {
                board[nr][nc] = '*';
                que.emplace(nr, nc);
            }
            else if (board[nr][nc] == 'P') {
                cnt++;
                board[nr][nc] = '*';
                que.emplace(nr, nc);
            }
        }
    }

    if (cnt == 0) cout << "TT\n";
    else cout << cnt << '\n';

    return 0;
}
