// Solve 2025-06-12

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ll MOD = (1LL << 31) - 1;

string board[1000];
ll memo[1000][1000];
bool visited[1000][1000];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    memo[0][0] = 1;
    visited[0][0] = true;

    for (int y = 1; y < n; y++) {
        if (board[0][y] == '.') {
            memo[0][y] = memo[0][y - 1];
            visited[0][y] = visited[0][y - 1];
        }
    }

    for (int x = 1; x < n; x++) {
        if (board[x][0] == '.') {
            memo[x][0] = memo[x - 1][0];
            visited[x][0] = visited[x - 1][0];
        }

        for (int y = 1; y < n; y++) {
            if (board[x][y] == '.') {
                memo[x][y] = (memo[x - 1][y] + memo[x][y - 1]) % MOD;
                visited[x][y] = visited[x - 1][y] || visited[x][y - 1];
            }
        }
    }

    if (visited[n - 1][n - 1]) {
        cout << memo[n - 1][n - 1] << '\n';
        return 0;
    }

    queue<pii> bfs_que;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[x][y]) {
                bfs_que.emplace(x, y);
            }
        }
    }

    while (!bfs_que.empty()) {
        pii cur = bfs_que.front();
        bfs_que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] != '.' || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            bfs_que.emplace(nx, ny);
        }
    }

    if (visited[n - 1][n - 1]) {
        cout << "THE GAME IS A LIE" << '\n';
    }
    else {
        cout << "INCONCEIVABLE" << '\n';
    }

    return 0;
}
