// Solve 2022-07-02
// Update 2023-03-04

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const ll MOD = 1e9;
ll dp[100][10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int j = 1; j <= 9; j++) {
        dp[0][j] = 1;
    }

    // 점화식을 이용하여 계산하기
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    // 결과 출력하기
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}