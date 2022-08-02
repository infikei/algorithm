#include <iostream>
using namespace std;

int DP[100001] = {0};

int dp(int x) {
    if (DP[x] > 0) {
        return DP[x];
    }
    int result = dp(x - 1) + 1;
    for (int i = 2; i * i < x; i++) {
        result = min(result, dp(x - i * i) + dp(i * i));
    }

    return DP[x] = result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i * i <= N; i++) {
        DP[i * i] = 1;
    }
    cout << dp(N) << '\n';

    return 0;
}