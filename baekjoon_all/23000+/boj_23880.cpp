// Solve 2025-06-14
// Update 2025-06-16

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

int n, k;
string board[50];
int memo[50][50][2][4];

void input() {
    cin >> n >> k;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }
}

void pro() {
    memset(memo, 0, sizeof memo);

    memo[0][0][0][0] = memo[0][0][1][0] = 1;

    for (int y = 1; y < n; y++) {
        if (board[0][y] != '.') continue;

        memo[0][y][0][0] = memo[0][y - 1][0][0];
    }

    for (int x = 1; x < n; x++) {
        if (board[x][0] != '.') continue;

        memo[x][0][1][0] = memo[x - 1][0][1][0];
    }

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n; y++) {
            if (board[x][y] != '.') continue;

            memo[x][y][0][0] = memo[x][y - 1][0][0];
            memo[x][y][1][0] = memo[x - 1][y][1][0];

            for (int i = 1; i <= k; i++) {
                memo[x][y][0][i] = memo[x][y - 1][0][i] + memo[x][y - 1][1][i - 1];
                memo[x][y][1][i] = memo[x - 1][y][1][i] + memo[x - 1][y][0][i - 1];
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= k; i++) {
        ans += memo[n - 1][n - 1][0][i];
        ans += memo[n - 1][n - 1][1][i];
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        input();
        pro();
    }

    return 0;
}
