#include <iostream>
using namespace std;

long long DP[101][10];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력 값 저장하기
    int N;
    cin >> N;

    // 초기값 설정하기
    DP[1][0] = 0;
    for (int j = 1; j <= 9; j++) {
        DP[1][j] = 1;
    }

    // 점화식을 이용하여 계산하기
    for (int i = 2; i <= N; i++) {
        DP[i][0] = DP[i - 1][1];
        DP[i][9] = DP[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
        }
    }

    // 결과 값 출력하기
    long long ans = DP[N][0];
    for (int j = 1; j <= 9; j++) {
        ans = (ans + DP[N][j]) % 1000000000;
    }
    cout << ans << "\n";

    return 0;
}