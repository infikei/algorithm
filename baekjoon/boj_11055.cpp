#include <iostream>
using namespace std;

int A[1001];
int DP_increase[1001];
int N, ans;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void DP_increase_fn() {
    ans = DP_increase[1] = A[1];

    for (int i = 2; i <= N; i++) {
        DP_increase[i] = A[i];

        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                DP_increase[i] = max(DP_increase[i], DP_increase[j] + A[i]);
            }
        }
        ans = max(ans, DP_increase[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    DP_increase_fn();

    cout << ans << '\n';

    return 0;
}