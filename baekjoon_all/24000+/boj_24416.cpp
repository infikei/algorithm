// Solve 2022-06-03
// Update 2023-10-10

#include <iostream>
using namespace std;

int main() {
    int dp[41] = { 0, 1, 1 };

    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;
    cin >> n;

    cout << dp[n] << ' ' << n - 2 << '\n';

    return 0;
}
