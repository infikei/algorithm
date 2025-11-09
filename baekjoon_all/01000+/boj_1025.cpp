// Solve 2025-11-09

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

int board[9][9];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            char c;
            cin >> c;
            board[x][y] = c - '0';
        }
    }

    int mx = -1;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dx = -x; dx <= n - 1 - x; dx++) {
                for (int dy = -y; dy <= m - 1 - y; dy++) {
                    if (dx == 0 && dy == 0) {
                        int num = board[x][y];
                        int sqrt_num = sqrt(num);

                        if (sqrt_num * sqrt_num == num) {
                            mx = max(mx, num);
                        }

                        continue;
                    }

                    int nx = x;
                    int ny = y;
                    int num = 0;

                    while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        num = num * 10 + board[nx][ny];
                        int sqrt_num = sqrt(num);

                        if (sqrt_num * sqrt_num == num) {
                            mx = max(mx, num);
                        }

                        nx += dx;
                        ny += dy;
                    }
                }
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
