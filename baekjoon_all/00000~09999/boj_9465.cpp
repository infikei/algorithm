#include <iostream>
using namespace std;

int sticker[2][100000];
int DP[2][100000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < N; col++) {
                cin >> sticker[row][col];
            }
        }

        for (int i = 0; i < 2; i++) {
            DP[i][0] = sticker[i][0];
        }

        if (N >= 2) {
            for (int i = 0; i < 2; i++) {
                DP[i][1] = DP[1 - i][0] + sticker[i][1];
            }
        }

        for (int j = 2; j < N; j++) {
            for (int i = 0; i < 2; i++) {
                DP[i][j] = max(DP[1 - i][j - 1], DP[1 - i][j - 2]) + sticker[i][j];
            }
        }

        cout << max(DP[0][N - 1], DP[1][N - 1]) << '\n';
    }

    return 0;
}