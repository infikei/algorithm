#include <iostream>
using namespace std;

int DP[31][31];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    // 초기값 세팅
    DP[1][0] = 1;
    DP[1][1] = 1;

    // n = 2부터 n = 30까지의 모든 nCr 값을 계산한다.
    for (int n = 2; n <= 30; n++) {
        for (int r = 0; r <= n; r++) {
            if (r == 0 || r == n) {
                DP[n][r] = 1;
            }
            else {
                DP[n][r] = DP[n - 1][r - 1] + DP[n - 1][r];
            }
        }
    }

    // 이제 주어진 입력값에 대한 결과값 출력
    int west, east;

    for (int t = 0; t < T; t++) {
        cin >> west >> east;
        cout << DP[east][west] << '\n';
    }

    return 0;
}