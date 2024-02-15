// Solve 2024-02-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double win, lose, draw;
    cin >> win >> lose >> draw;

    double dp[21][62] = { 0.0 };
    dp[0][40] = 1.0;

    for (int round = 1; round <= 20; round++) {
        for (int score = 10; score <= 60; score++) {
            dp[round][score] = dp[round - 1][score - 1] * win + dp[round - 1][score] * draw + dp[round - 1][score + 1] * lose;
        }
    }

    double prob_by_tier[5] = { 0.0 };

    for (int score = 20; score < 30; score++) {
        prob_by_tier[0] += dp[20][score];
    }

    for (int score = 30; score < 40; score++) {
        prob_by_tier[1] += dp[20][score];
    }

    for (int score = 40; score < 50; score++) {
        prob_by_tier[2] += dp[20][score];
    }

    for (int score = 50; score < 60; score++) {
        prob_by_tier[3] += dp[20][score];
    }

    prob_by_tier[4] = dp[20][60];

    SETPRECISION(8);

    for (int i = 0; i < 5; i++) {
        cout << prob_by_tier[i] << '\n';
    }

    return 0;
}
