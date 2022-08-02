#include <iostream>
using namespace std;

int DP[1001][1001];
int N, K;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    DP[1][0] = 1;
    DP[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                DP[i][j] = 1;
            }
            else {
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % 10007;
            }
        }
    }

    cout << DP[N][K] << '\n';

    return 0;
}