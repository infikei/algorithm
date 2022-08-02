#include <iostream>
using namespace std;

int P[1001];
int DP[1001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        DP[i] = P[i];
        for (int j = 1; j <= i / 2; j++) {
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}