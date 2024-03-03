// Solve 2023-02-03
// Update 2024-03-02

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m, nm;
int board[8][8];
bool visited[8][8];
vector<Point> viruses;
int wall_count;
int max_safe_count, cur_safe_count;

void dfs(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 1 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            cur_safe_count--;
            dfs(nx, ny);
        }
    }
}

void update_max_safe_count() {
    cur_safe_count = nm - (wall_count + 3);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            visited[x][y] = false;
        }
    }

    for (Point &virus : viruses) {
        if (!visited[virus.x][virus.y]) {
            visited[virus.x][virus.y] = true;
            cur_safe_count--;
            dfs(virus.x, virus.y);
        }
    }

    max_safe_count = max(max_safe_count, cur_safe_count);
}

int main() {
    FASTIO;

    cin >> n >> m;
    nm = n * m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];

            if (board[x][y] == 2) {
                viruses.emplace_back(x, y);
            }
            else if (board[x][y] == 1) {
                wall_count++;
            }
        }
    }

    for (int i = 0; i < nm; i++) {
        int ix = i / m;
        int iy = i % m;

        if (board[ix][iy] != 0) continue;

        board[ix][iy] = 1;

        for (int j = i + 1; j < nm; j++) {
            int jx = j / m;
            int jy = j % m;

            if (board[jx][jy] != 0) continue;

            board[jx][jy] = 1;

            for (int k = j + 1; k < nm; k++) {
                int kx = k / m;
                int ky = k % m;

                if (board[kx][ky] != 0) continue;

                board[kx][ky] = 1;
                update_max_safe_count();
                board[kx][ky] = 0;
            }

            board[jx][jy] = 0;
        }

        board[ix][iy] = 0;
    }

    cout << max_safe_count << '\n';

    return 0;
}
