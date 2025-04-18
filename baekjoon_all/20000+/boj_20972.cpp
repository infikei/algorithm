// Solve 2025-04-18

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        int row_sum[2] = { 0 };

        for (int y = 0; y < n; y++) {
            row_sum[y % 2] += board[x][y];
        }

        ans += max(row_sum[0], row_sum[1]);
    }

    int ans2 = 0;

    for (int y = 0; y < n; y++) {
        int col_sum[2] = { 0 };

        for (int x = 0; x < n; x++) {
            col_sum[x % 2] += board[x][y];
        }

        ans2 += max(col_sum[0], col_sum[1]);
    }

    cout << max(ans, ans2) << '\n';

    return 0;
}
