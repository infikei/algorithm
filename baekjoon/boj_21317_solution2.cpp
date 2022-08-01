#include <iostream>
using namespace std;

int jump[20][2];
int DP[21][2];
int N, K, ans;

void input() {
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> jump[i][0] >> jump[i][1];
    }
    cin >> K;
}

void find_energy() {
    DP[1][0] = 0;
    DP[2][0] = jump[1][0];

    for (int i = 3; i <= N; i++) {
        DP[i][0] = min(DP[i - 1][0] + jump[i - 1][0], DP[i - 2][0] + jump[i - 2][1]);
    }

    ans = DP[N][0];
}

void find_energy_with_very_big_jump() {
    DP[4][1] = DP[1][0] + K;
    DP[5][1] = min(DP[2][0] + K, DP[4][1] + jump[4][0]);

    for (int i = 6; i <= N; i++) {
        DP[i][1] = min(DP[i - 3][0] + K, DP[i - 1][1] + jump[i - 1][0]);
        DP[i][1] = min(DP[i][1], DP[i - 2][1] + jump[i - 2][1]);
    }

    ans = min(ans, DP[N][1]);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    find_energy();
    if (N >= 4) {
        find_energy_with_very_big_jump();
    }

    cout << ans << '\n';

    return 0;
}