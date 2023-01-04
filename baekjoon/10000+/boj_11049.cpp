#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 500;
int n, r[MAX_N + 1], c[MAX_N + 1], dp[MAX_N + 1][MAX_N + 1];

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> c[i];
    }

    // dp 배열 : istart번째부터 iend번째까지의 행렬들을 곱할 때 필요한 곱셈 연산 횟수의 최솟값을 저장하는 배열
    for (int ilen = 2; ilen <= n; ilen++) {
        for (int istart = 1; istart <= n + 1 - ilen; istart++) {
            int iend = istart + ilen - 1;
            dp[istart][iend] = dp[istart + 1][iend] + r[istart] * c[istart] * c[iend];
            for (int j = istart + 1; j < iend; j++) {
                dp[istart][iend] = min(dp[istart][iend], dp[istart][j] + dp[j + 1][iend] + r[istart] * c[j] * c[iend]);
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}