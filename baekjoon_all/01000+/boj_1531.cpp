// Solve 2023-10-25
// Update 2025-03-03

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

int board[101][101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;

        for (int x = x0; x <= x1; x++) {
            for (int y = y0; y <= y1; y++) {
                board[x][y]++;
            }
        }
    }

    int ans = 0;

    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            if (board[x][y] > m) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
