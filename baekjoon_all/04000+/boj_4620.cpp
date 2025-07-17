// Solve 2025-07-16

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

int n;
string board[34];
ll memo[34][34];

ll dfs(int x, int y) {
    if (x >= n || y >= n) return 0;
    if (memo[x][y] != -1) return memo[x][y];

    int num = board[x][y] - '0';

    if (num == 0) return 0;

    return memo[x][y] = dfs(x, y + num) + dfs(x + num, y);
}

int main() {
    FASTIO;

    while (true) {
        cin >> n;

        if (n == -1) break;

        for (int x = 0; x < n; x++) {
            cin >> board[x];
        }

        memset(memo, -1, sizeof memo);
        memo[n - 1][n - 1] = 1;
        cout << dfs(0, 0) << '\n';
    }

    return 0;
}
