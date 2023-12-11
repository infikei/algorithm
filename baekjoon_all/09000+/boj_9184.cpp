// Solve 2022-06-03
// Update 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21, 1)));

    for (int a = 1; a < 21; a++) {
        for (int b = 1; b < 21; b++) {
            for (int c = 1; c < 21; c++) {
                if (a < b && b < c) {
                    dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
                }
                else {
                    dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
                }
            }
        }
    }

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        int ans;

        if (a <= 0 || b <= 0 || c <= 0) {
            ans = 1;
        }
        else if (a > 20 || b > 20 || c > 20) {
            ans = dp[20][20][20];
        }
        else {
            ans = dp[a][b][c];
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }

    return 0;
}
