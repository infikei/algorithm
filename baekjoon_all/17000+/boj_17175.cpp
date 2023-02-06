#include <iostream>
using namespace std;

int N;
int DP[51];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= N; i++) {
        DP[i] = (1 + DP[i - 2] + DP[i - 1]) % 1000000007;
    }

    cout << DP[N] << '\n';

    return 0;
}