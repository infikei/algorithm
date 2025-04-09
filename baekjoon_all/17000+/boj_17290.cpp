// Solve 2025-04-08

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

string board[10];

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;
    r--;
    c--;

    for (int x = 0; x < 10; x++) {
        cin >> board[x];
    }

    bool row_check[10] = { false };
    bool col_check[10] = { false };

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (board[x][y] == 'o') {
                row_check[x] = true;
                col_check[y] = true;
            }
        }
    }

    int ans = 1000;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (!row_check[x] && !col_check[y]) {
                ans = min(ans, abs(x - r) + abs(y - c));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
