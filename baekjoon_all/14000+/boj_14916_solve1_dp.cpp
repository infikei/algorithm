#include <iostream>
using namespace std;

int DP[100001];
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    DP[1] = DP[3] = -1;
    DP[2] = DP[5] = 1;
    DP[4] = DP[7] = 2;
    DP[6] = 3;
    DP[8] = 4;

    cin >> N;

    for (int i = 9; i <= N; i++) {
        DP[i] = min(DP[i - 2] + 1, DP[i - 5] + 1);
    }

    cout << DP[N] << '\n';

    return 0;
}