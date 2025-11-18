// Solve 2025-11-18

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

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {0, 1, -1, 1, -1, 0};
int color[50][50];

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<string> board(n);

    for (string& row : board) {
        cin >> row;
    }

    queue<pii> que;
    int mx = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] != 'X' || color[x][y] != 0) continue;

            mx = max(mx, 1);
            color[x][y] = 1;
            que.emplace(x, y);

            while (!que.empty()) {
                auto [xx, yy] = que.front();
                que.pop();

                for (int d = 0; d < 6; d++) {
                    int nx = xx + dx[d];
                    int ny = yy + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != 'X') continue;

                    // 2가지 색으로 칠할 때 모순이 발생한다면 적어도 3가지의 색이 필요함
                    if (color[nx][ny] != 0) {
                        if (color[xx][yy] == color[nx][ny]) {
                            cout << 3 << '\n';
                            return 0;
                        }

                        continue;
                    }

                    mx = max(mx, 2);
                    color[nx][ny] = (color[xx][yy] == 1 ? 2 : 1);
                    que.emplace(nx, ny);
                }
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
