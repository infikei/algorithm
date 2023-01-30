#include <iostream>
using namespace std;

int N, ans0, ans1;
int A[200001];
int B[200001];
int DP[200001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    ans1 = -7654321;

    for (int i = 1; i <= N; i++) {
        // sum
        if (B[i] == 1) {
            ans0 += A[i];
        }

        // dp
        int now = A[i];
        if (B[i] == 1) {
            now = -now;
        }
        DP[i] = max(now, DP[i - 1] + now);
        ans1 = max(ans1, DP[i]);
    }

    cout << ans0 + ans1 << '\n';

    return 0;
}