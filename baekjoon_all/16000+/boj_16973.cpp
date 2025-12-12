// Solve 2025-12-10

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

int board[1001][1001];
int board2[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    int h, w, sr, sc, fr, fc;
    cin >> h >> w >> sr >> sc >> fr >> fc;

    if (sr == fr && sc == fc) {
        cout << 0 << '\n';
        return 0;
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            board[x][y] += board[x][y - 1] + board[x - 1][y] - board[x - 1][y - 1];
        }
    }

    for (int x = 1, xe = h; xe <= n; x++, xe++) {
        for (int y = 1, ye = w; ye <= m; y++, ye++) {
            board2[x][y] = board[xe][ye] - board[xe][y - 1] - board[x - 1][ye] + board[x - 1][y - 1];
        }
    }

    queue<pii> que;
    que.emplace(sr, sc);
    visited[sr][sc] = true;
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

                if (nx < 1 || nx > n - h + 1 || ny < 1 || ny > m - w + 1) continue;
                if (visited[nx][ny] || board2[nx][ny] > 0) continue;

                visited[nx][ny] = true;
                que.emplace(nx, ny);

                if (nx == fr && ny == fc) {
                    cout << level << '\n';
                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
