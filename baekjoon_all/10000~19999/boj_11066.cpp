#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int K_MAX = 500;
int file[K_MAX + 1], file_sum[K_MAX + 1], dp[K_MAX + 1][K_MAX + 1];

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;

        for (int i = 1; i <= K; i++) {
            cin >> file[i];
            file_sum[i] = file_sum[i - 1] + file[i];
        }

        for (int ilen = 2; ilen <= K; ilen++) {
            for (int ib = 1; ib <= K + 1 - ilen; ib++) {
                int ie = ib + ilen - 1;

                dp[ib][ie] = dp[ib][ib] + dp[ib + 1][ie];
                for (int k = ib + 2; k < ib + ilen; k++) {
                    dp[ib][ie] = min(dp[ib][ie], dp[ib][k - 1] + dp[k][ie]);
                }

                dp[ib][ie] += file_sum[ie] - file_sum[ib - 1];
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}