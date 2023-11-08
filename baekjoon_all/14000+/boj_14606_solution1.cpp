// Solve 2023-11-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[11] = { 0 };

    for (int i = 2; i < 11; i++) {
        int a = i / 2;
        int b = i - a;

        dp[i] = dp[a] + dp[b] + a * b;
    }

    int n;
    cin >> n;

    cout << dp[n] << '\n';

    return 0;
}
