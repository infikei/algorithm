// Solve 2025-03-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int board[1000][1000];
int memo[1000][1000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    int cur = 0;

    for (int y = 0; y < m; y++) {
        cur += board[0][y];
        memo[0][y] = cur;
    }

    for (int x = 1; x < n; x++) {
        cur = memo[x - 1][0];

        for (int y = 0; y < m; y++) {
            cur = max(cur, memo[x - 1][y]) + board[x][y];
            memo[x][y] = cur;
        }

        cur = memo[x - 1][m - 1];

        for (int y = m - 1; y >= 0; y--) {
            cur = max(cur, memo[x - 1][y]) + board[x][y];
            memo[x][y] = max(memo[x][y], cur);
        }
    }

    cout << memo[n - 1][m - 1] << '\n';

    return 0;
}
