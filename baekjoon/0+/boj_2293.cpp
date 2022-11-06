#include <iostream>
using namespace std;

int N, K;
int coin[100];
int DP[10001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    DP[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = coin[i]; j <= K; j++) {
            DP[j] += DP[j - coin[i]];
        }
    }

    cout << DP[K] << '\n';

    return 0;
}