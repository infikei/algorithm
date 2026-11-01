// Solve 2026-08-22

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

vector<string> board;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int h, w, k;
    cin >> h >> w >> k;

    for (int x = 0; x < h; x++) {
        string row;
        cin >> row;
        board.push_back(row);
    }

    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<bool> row_bomb(h);
    vector<bool> col_bomb(w);

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (board[x][y] == '#') {
                visited[x][y] = true;
                row_bomb[x] = true;
                col_bomb[y] = true;
            }
        }
    }

    queue<pii> que;
    int cnt = 0;

    for (int x = 0; x < h; x++) {
        if (row_bomb[x]) continue;

        for (int y = 0; y < w; y++) {
            if (col_bomb[y]) continue;

            cnt++;
            visited[x][y] = true;
            que.emplace(x, y);
        }
    }

    while (k-- > 0) {
        int iter = size(que);

        while (iter-- > 0) {
            auto [cx, cy] = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (visited[nx][ny]) continue;

                cnt++;
                visited[nx][ny] = true;
                que.emplace(nx, ny);
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
