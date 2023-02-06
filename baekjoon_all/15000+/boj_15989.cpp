#include <iostream>
using namespace std;

int T, N;
int DP[10001][3];

void dp_calc() {
    DP[1][0] = 1;
    DP[2][0] = 1;
    DP[2][1] = 1;
    DP[3][0] = 2;
    DP[3][1] = 0;
    DP[3][2] = 1;

    for (int i = 4; i < 10001; i++) {
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2];
        DP[i][1] = DP[i - 2][1] + DP[i - 2][2];
        DP[i][2] = DP[i - 3][2];
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    dp_calc();

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        cout << DP[N][0] + DP[N][1] + DP[N][2] << '\n';
    }

    return 0;
}