#include <iostream>
using namespace std;

const int SIZE = 10000;
int N;
double A[SIZE], DP[SIZE], ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    cin >> A[0];
    DP[0] = A[0];
    ans = A[0];

    for (int i = 1; i < N; i++) {
        cin >> A[i];
        DP[i] = max(DP[i - 1] * A[i], A[i]);
        ans = max(ans, DP[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << ans << '\n';

    return 0;
}