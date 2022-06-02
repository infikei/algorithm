#include <iostream>
using namespace std;

int main()
{
    int n;
    int dp[41] = {0};
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 41; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cin >> n;
    cout << dp[n] << " " << (n - 2) << "\n";

    return 0;
}