#include <iostream>
using namespace std;

int dp[31][31];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    // 초기값 세팅
    dp[1][0] = 1;
    dp[1][1] = 1;

    // n = 2부터 n = 30까지의 모든 nCr 값을 계산한다.
    for (int n = 2; n <= 30; n++) {
        for (int r = 0; r <= n; r++) {
            if (r == 0 || r == n) {
                dp[n][r] = 1;
            }
            else {
                dp[n][r] = dp[n - 1][r - 1] + dp[n - 1][r];
            }
        }
    }

    // 이제 주어진 입력값에 대한 결과값 출력
    int west, east;

    for (int t = 0; t < T; t++) {
        cin >> west >> east;
        cout << dp[east][west] << "\n";
    }

    return 0;
}