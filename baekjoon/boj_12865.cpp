#include <iostream>
using namespace std;

int Weight[100], Value[100];
int DP[101][100001];
int N, K, ans;

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> Weight[i] >> Value[i];
    }
}

void solve() {
    for (int n = 0; n <= N; n++) {
        DP[n][0] = 0;
    }
    for (int k = 0; k <= K; k++) {
        DP[0][k] = 0;
    }

    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n++) {
            if (Weight[n - 1] > k) {
                DP[n][k] = DP[n - 1][k];
            }
            else {
                DP[n][k] = max(DP[n - 1][k - Weight[n - 1]] + Value[n - 1], DP[n - 1][k]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << DP[N][K] << '\n';

    return 0;
}