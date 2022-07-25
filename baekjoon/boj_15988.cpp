#include <iostream>
using namespace std;

int DP[1000001] = {0};
int T, N;

int DP_fn(int N) {
    if (DP[N] > 0) {
        return DP[N];
    }
    int result = (DP_fn(N - 1) + DP_fn(N - 2)) % 1000000009;
    result = (result + DP_fn(N - 3)) % 1000000009;
    DP[N] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        cout << DP_fn(N) << '\n';
    }

    return 0;
}