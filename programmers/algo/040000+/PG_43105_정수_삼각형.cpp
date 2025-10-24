// Solve 2025-10-24

#include <bits/stdc++.h>

using namespace std;

int memo[500][500];

int solution(vector<vector<int>> triangle) {
    int n = size(triangle);
    memo[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        memo[i][0] = memo[i - 1][0] + triangle[i][0];
        memo[i][i] = memo[i - 1][i - 1] + triangle[i][i];

        for (int j = 1; j < i; j++) {
            memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + triangle[i][j];
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, memo[n - 1][i]);
    }

    return mx;
}
