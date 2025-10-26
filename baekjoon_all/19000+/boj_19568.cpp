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

int board[30][30];

int main() {
    FASTIO;

    for (int y = 0; y <= 14; y++) {
        board[15][y] = 1;
    }

    for (int y = 16; y <= 29; y++) {
        board[15][y] = 15;
    }

    for (int x = 1; x <= 14; x++) {
        board[x][15] = 15 * 15;
    }

    for (int x = 16; x <= 29; x++) {
        board[x][15] = 15 * 15 * 15;
    }

    for (int x = 0; x < 30; x++) {
        for (int y = 0; y < 30; y++) {
            cout << board[x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
