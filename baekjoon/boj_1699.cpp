#include <iostream>
using namespace std;

int dp[100001] = {0};

int f(int x) {
    if (dp[x] > 0) {
        return dp[x];
    }
    int result = f(x - 1) + 1;
    for (int i = 2; i * i < x; i++) {
        result = min(result, f(x - i * i) + f(i * i));
    }
    dp[x] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i * i <= N; i++) {
        dp[i * i] = 1;
    }
    cout << f(N) << "\n";

    return 0;
}