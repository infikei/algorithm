#include <iostream>
using namespace std;

int T[16];
int P[16];
int DP[16];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    int ans = 0;
    DP[N] = 0;

    for (int i = N; i >= 1; i--) {
        DP[i] = 0;
        for (int j = i + T[i]; j <= N + 1; j++) {
            DP[i] = max(DP[i], P[i] + DP[j]);
        }
        ans = max(ans, DP[i]);
    }

    cout << ans << '\n';

    return 0;
}