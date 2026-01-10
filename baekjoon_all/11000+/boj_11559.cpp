// Solve 2026-01-09

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

bool visited[12][6];
string board[12];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bomb() {
    memset(visited, false, sizeof visited);
    bool ret = false;

    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 6; c++) {
            if (visited[r][c] || board[r][c] == '.') continue;

            vector<pii> vec;
            queue<pii> que;
            vec.emplace_back(r, c);
            que.emplace(r, c);
            visited[r][c] = true;

            while (!que.empty()) {
                auto [x, y] = que.front();
                que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                    if (visited[nx][ny] || board[nx][ny] != board[r][c]) continue;

                    visited[nx][ny] = true;
                    vec.emplace_back(nx, ny);
                    que.emplace(nx, ny);
                }
            }

            if (size(vec) >= 4) {
                ret = true;

                for (auto [x, y] : vec) {
                    board[x][y] = '.';
                }
            }
        }
    }

    return ret;
}

void gravity() {
    for (int y = 0; y < 6; y++) {
        for (int x = 11; x >= 0; x--) {
            if (board[x][y] == '.') continue;

            char c = board[x][y];
            board[x][y] = '.';
            int nx = x;

            while (nx + 1 < 12 && board[nx + 1][y] == '.') {
                nx++;
            }

            board[nx][y] = c;
        }
    }
}

int main() {
    FASTIO;

    for (int x = 0; x < 12; x++) {
        cin >> board[x];
    }

    int ans = 0;

    while (bomb()) {
        gravity();
        ans++;
    }

    cout << ans << '\n';
    return 0;
}
