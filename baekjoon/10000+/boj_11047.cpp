#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, K;
    cin >> N >> K;

    int coin[10];
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans += (K / coin[i]);
        K = K % coin[i];
        if (K == 0) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}