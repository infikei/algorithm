#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 80, MAX_X = 200;
int n, k, x;
int a[MAX_N + 1], b[MAX_N + 1];
bool dp[MAX_N + 1][MAX_N + 1][MAX_N * MAX_X + 1];

int main() {
    fastio;

    cin >> n >> k >> x;

    int max_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        max_a = max(max_a, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1][a[i]] = true;
        for (int j = 1; j <= k; j++) {
            for (int m = 1; m <= j * max_a; m++) {
                if (dp[i - 1][j][m] || (m >= a[i] && dp[i - 1][j - 1][m - a[i]])) {
                    dp[i][j][m] = true;
                }
            }
        }
    }

    int max_sum_a = 0, kx = k * x;
    for (int m = 1; m <= k * max_a; m++) {
        if (!dp[n][k][m]) continue;
        if (abs(kx - 2 * m) < abs(kx - 2 * max_sum_a)) {
            max_sum_a = m;
        }
    }

    int ans = max_sum_a * (k * x - max_sum_a);
    cout << ans << '\n';

    return 0;
}