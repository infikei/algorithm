#include <iostream>
using namespace std;

int A[1001];
int DP_increase[1001];
int DP_decrease[1001];
int N, ans;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void DP_increase_fn() {
    DP_increase[1] = 1;

    for (int i = 2; i <= N; i++) {
        DP_increase[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                DP_increase[i] = max(DP_increase[i], DP_increase[j] + 1);
            }
        }
    }
}

void DP_decrease_fn() {
    DP_decrease[N] = 1;

    for (int i = N - 1; i >= 1; i--) {
        DP_decrease[i] = 1;
        for (int j = N; j > i; j--) {
            if (A[j] < A[i]) {
                DP_decrease[i] = max(DP_decrease[i], DP_decrease[j] + 1);
            }
        }
    }
}

void DP_bitonic_fn() {
    ans = 0;

    for (int i = 1; i <= N; i++) {
        ans = max(ans, DP_increase[i] + DP_decrease[i] - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    DP_increase_fn();
    DP_decrease_fn();
    DP_bitonic_fn();

    cout << ans << '\n';

    return 0;
}