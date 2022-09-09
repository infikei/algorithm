#include <iostream>
#include <cmath>
using namespace std;

int DP[50001];

void initialize_DP() {
    int i = 1;

    while (true) {
        if (i * i > 50000) {
            break;
        }
        DP[i * i] = 1;
        i++;
    }
}

int dp(int n) {
    if (DP[n] > 0) {
        return DP[n];
    }

    double sqrt_n = sqrt(n);
    int result = 99999;

    for (int i = 1; i < sqrt_n; i++) {
        result = min(result, dp(i * i) + dp(n - i * i));
    }
    DP[n] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    initialize_DP();
    cout << dp(N) << '\n';

    return 0;
}