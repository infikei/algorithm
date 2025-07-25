// Solve 2022-09-14
// Update 2025-07-14

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

int board[100][100];
ll memo[100][100];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    memo[n - 1][n - 1] = 1;

    for (int x = n - 1; x >= 0; x--) {
        for (int y = n - 1; y >= 0; y--) {
            int num = board[x][y];

            if (num == 0) continue;

            if (x + num < n) {
                memo[x][y] += memo[x + num][y];
            }

            if (y + num < n) {
                memo[x][y] += memo[x][y + num];
            }
        }
    }

    cout << memo[0][0] << '\n';
    return 0;
}
