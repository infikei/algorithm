#include <iostream>
using namespace std;

const int SIZE = 1500001;
int T[SIZE];
int P[SIZE];
int DP[SIZE];
int DP_max = 0;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP_max, DP[i]);

        if (i + T[i] - 1 <= N) {
            DP[i + T[i] - 1] = max(DP[i + T[i] - 1], DP[i - 1] + P[i]);
        }

        DP_max = DP[i];
    }

    cout << DP_max << '\n';

    return 0;
}