// Solve 2026-01-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int board[1000][1000];
int area[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    sr--;
    sc--;
    er--;
    ec--;

    queue<pii> que;
    que.emplace(sr, sc);
    area[sr][sc] = 1;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0 || area[nx][ny] == 1) continue;

            area[nx][ny] = 1;
            que.emplace(nx, ny);
        }
    }

    if (area[er][ec] == 1) {
        cout << 0 << '\n';
        return 0;
    }

    que.emplace(er, ec);
    area[er][ec] = 2;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0 || area[nx][ny] == 2) continue;

            area[nx][ny] = 2;
            que.emplace(nx, ny);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (area[x][y] == 1) {
                que.emplace(x, y);
            }
        }
    }

    int level = 0;

    while (!que.empty()) {
        level++;
        int iter = size(que);

        while (iter-- > 0) {
            auto [x, y] = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (area[nx][ny] == 2) {
                    cout << level << '\n';
                    return 0;
                }

                if (area[nx][ny] == 0) {
                    area[nx][ny] = 3;
                    que.emplace(nx, ny);
                }
            }
        }
    }

    return 0;
}
