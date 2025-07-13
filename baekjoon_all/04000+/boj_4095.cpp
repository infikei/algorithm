// Solve 2025-07-08

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

int n, m;
int board[1001][1001];

bool input() {
    cin >> n >> m;

    if (n == 0 && m == 0) return false;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    return true;
}

void pro() {
    int ans = 0;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (board[x][y] == 0) continue;

            board[x][y] = min(board[x][y - 1], min(board[x - 1][y - 1], board[x - 1][y])) + 1;
            ans = max(ans, board[x][y]);
        }
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    while (input()) {
        pro();
    }

    return 0;
}
