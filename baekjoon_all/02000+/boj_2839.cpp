// Solve 2024-02-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[15] = { 0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4 };
    int n;
    cin >> n;

    cout << ((n == 4 || n == 7) ? -1 : (n / 15 * 3 + dp[n % 15])) << '\n';

    return 0;
}
