#include <iostream>
using namespace std;

int DP[100001][3];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    DP[1][0] = 1; // 1 = 1
    DP[2][1] = 1; // 2 = 2
    DP[3][0] = 1; // 3 = 2 + 1
    DP[3][1] = 1; // 3 = 1 + 2
    DP[3][2] = 1; // 3 = 3

    for (int i = 4; i < 100001; i++) {
        DP[i][0] = (DP[i - 1][1] + DP[i - 1][2]) % 1000000009;
        DP[i][1] = (DP[i - 2][0] + DP[i - 2][2]) % 1000000009;
        DP[i][2] = (DP[i - 3][0] + DP[i - 3][1]) % 1000000009;
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int ans = DP[N][0];
        ans = (ans + DP[N][1]) % 1000000009;
        ans = (ans + DP[N][2]) % 1000000009;
        cout << ans << '\n';
    }

    return 0;
}