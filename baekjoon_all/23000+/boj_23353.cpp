// Solve 2025-07-20

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        int cur[2] = {0};

        for (int y = 0; y < n; y++) {
            if (board[x][y] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[x][y] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }
        }

        ans = max(ans, max(cur[0], cur[1]));

        // 오른쪽 위 방향
        cur[0] = cur[1] = 0;
        int px = x;
        int py = 0;

        while (px >= 0) {
            if (board[px][py] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[px][py] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }

            px--;
            py++;
        }

        ans = max(ans, max(cur[0], cur[1]));

        // 오른쪽 아래 방향
        cur[0] = cur[1] = 0;
        px = x;
        py = 0;

        while (px < n) {
            if (board[px][py] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[px][py] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }

            px++;
            py++;
        }

        ans = max(ans, max(cur[0], cur[1]));
    }

    for (int y = 0; y < n; y++) {
        int cur[2] = {0};

        for (int x = 0; x < n; x++) {
            if (board[x][y] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[x][y] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }
        }

        ans = max(ans, max(cur[0], cur[1]));

        // 오른쪽 아래 방향
        cur[0] = cur[1] = 0;
        int px = 0;
        int py = y;

        while (py < n) {
            if (board[px][py] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[px][py] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }

            px++;
            py++;
        }

        ans = max(ans, max(cur[0], cur[1]));

        // 오른쪽 위 방향
        cur[0] = cur[1] = 0;
        px = n - 1;
        py = y;

        while (py < n) {
            if (board[px][py] == 0) {
                ans = max(ans, max(cur[0], cur[1]));
                cur[0] = cur[1] = 0;
            }
            else if (board[px][py] == 1) {
                cur[0]++;
                cur[1]++;
            }
            else {
                ans = max(ans, cur[1]);
                cur[1] = cur[0] + 1;
                cur[0] = 0;
            }

            px--;
            py++;
        }

        ans = max(ans, max(cur[0], cur[1]));
    }

    cout << ans << '\n';
    return 0;
}
