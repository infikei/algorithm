// Solve 2026-04-21

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

int n, w;
int board[2][10001];
int memo[3][10001];

int dp() {
    memset(memo, 0x3f, sizeof(memo));
    memo[0][0] = 0;

    for (int j = 1; j <= n; j++) {
        memo[1][j] = memo[0][j - 1] + 1;
        memo[2][j] = memo[0][j - 1] + 1;

        if (board[0][j - 1] + board[0][j] <= w) {
            memo[1][j] = min(memo[1][j], memo[2][j - 1] + 1);
        }

        if (board[1][j - 1] + board[1][j] <= w) {
            memo[2][j] = min(memo[2][j], memo[1][j - 1] + 1);
        }

        memo[0][j] = min(memo[1][j], memo[2][j]) + 1;

        if (board[0][j] + board[1][j] <= w) {
            memo[0][j] = min(memo[0][j], memo[0][j - 1] + 1);
        }

        if (j >= 2 && board[0][j - 1] + board[0][j] <= w && board[1][j - 1] + board[1][j] <= w) {
            memo[0][j] = min(memo[0][j], memo[0][j - 2] + 2);
        }
    }

    return memo[0][n];
}

int dp2() {
    if (n < 2 || board[0][1] + board[0][n] > w) {
        return INF;
    }

    int ul = board[0][1];
    int ur = board[0][n];

    board[0][1] = INF;
    board[0][n] = INF;

    int mn = dp() - 1;

    board[0][1] = ul;
    board[0][n] = ur;

    return mn;
}

int dp3() {
    if (n < 2 || board[1][1] + board[1][n] > w) {
        return INF;
    }

    int dl = board[1][1];
    int dr = board[1][n];

    board[1][1] = INF;
    board[1][n] = INF;

    int mn = dp() - 1;

    board[1][1] = dl;
    board[1][n] = dr;

    return mn;
}

int dp4() {
    if (n < 2 || board[0][1] + board[0][n] > w || board[1][1] + board[1][n] > w) {
        return INF;
    }

    int ul = board[0][1];
    int ur = board[0][n];
    int dl = board[1][1];
    int dr = board[1][n];

    board[0][1] = INF;
    board[0][n] = INF;
    board[1][1] = INF;
    board[1][n] = INF;

    int mn = dp() - 2;

    board[0][1] = ul;
    board[0][n] = ur;
    board[1][1] = dl;
    board[1][n] = dr;

    return mn;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n >> w;

        board[0][0] = INF;
        board[1][0] = INF;

        for (int j = 1; j <= n; j++) {
            cin >> board[0][j];
        }

        for (int j = 1; j <= n; j++) {
            cin >> board[1][j];
        }

        int mn = dp();
        mn = min(mn, dp2());
        mn = min(mn, dp3());
        mn = min(mn, dp4());

        cout << mn << '\n';
    }

    return 0;
}
