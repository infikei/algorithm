// Solve 2026-02-10

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

string board[50];
int white[50], blue[50], red[50];
int memo[50][3];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 'W') {
                white[x]++;
            }
            else if (board[x][y] == 'B') {
                blue[x]++;
            }
            else {
                red[x]++;
            }
        }
    }

    memo[0][0] = white[0];

    for (int x = 1; x < n; x++) {
        memo[x][0] = memo[x - 1][0] + white[x];
    }

    memo[0][1] = -INF;

    for (int x = 1; x < n; x++) {
        memo[x][1] = max(memo[x - 1][0], memo[x - 1][1]) + blue[x];
    }

    memo[0][2] = -INF;
    memo[1][2] = -INF;

    for (int x = 2; x < n; x++) {
        memo[x][2] = max(memo[x - 1][1], memo[x - 1][2]) + red[x];
    }

    int ans = n * m - memo[n - 1][2];
    cout << ans << '\n';
    return 0;
}
