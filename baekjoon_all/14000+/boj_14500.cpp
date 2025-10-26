// Solve 2025-10-26

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

int board[504][504];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    int mx = 0;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            // 노란색, 연두색 모양

            int garo2 = board[x][y] + board[x][y + 1];
            mx = max(mx, garo2 + board[x + 1][y - 1] + board[x + 1][y]);
            mx = max(mx, garo2 + board[x + 1][y] + board[x + 1][y + 1]);
            mx = max(mx, garo2 + board[x + 1][y + 1] + board[x + 1][y + 2]);

            int sero2 = board[x][y] + board[x + 1][y];
            mx = max(mx, sero2 + board[x - 1][y + 1] + board[x][y + 1]);
            mx = max(mx, sero2 + board[x + 1][y + 1] + board[x + 2][y + 1]);

            // 주황색, 분홍색, 하늘색 모양

            int garo3 = garo2 + board[x][y + 2];
            int garo3_adj_max = board[x][y + 3];

            for (int ny = y; ny <= y + 2; ny++) {
                garo3_adj_max = max(garo3_adj_max, board[x - 1][ny]);
                garo3_adj_max = max(garo3_adj_max, board[x + 1][ny]);
            }

            mx = max(mx, garo3 + garo3_adj_max);

            int sero3 = sero2 + board[x + 2][y];
            int sero3_adj_max = board[x + 3][y];

            for (int nx = x; nx <= x + 2; nx++) {
                sero3_adj_max = max(sero3_adj_max, board[nx][y - 1]);
                sero3_adj_max = max(sero3_adj_max, board[nx][y + 1]);
            }

            mx = max(mx, sero3 + sero3_adj_max);
        }
    }

    cout << mx << '\n';
    return 0;
}
