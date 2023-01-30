#include <iostream>
using namespace std;

int jump[20][2];
int DP[21];
int DP_reverse[21];
int N, K, ans;

void input() {
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> jump[i][0] >> jump[i][1];
    }
    cin >> K;
}

void find_energy() {
    DP[1] = 0;
    DP[2] = jump[1][0];

    for (int i = 3; i <= N; i++) {
        DP[i] = min(DP[i - 1] + jump[i - 1][0], DP[i - 2] + jump[i - 2][1]);
    }
    
    ans = DP[N];
}

void find_energy_with_very_big_jump() {
    DP_reverse[N] = 0;
    DP_reverse[N - 1] = jump[N - 1][0];

    for (int i = N - 2; i >= 1; i--) {
        DP_reverse[i] = min(DP_reverse[i + 1] + jump[i][0], DP_reverse[i + 2] + jump[i][1]);
    }

    int energy_with_very_big_jump = DP[1] + K + DP_reverse[4];
    for (int i = 1; i <= N - 3; i++) {
        energy_with_very_big_jump = min(energy_with_very_big_jump, DP[i] + K + DP_reverse[i + 3]);
    }

    ans = min(ans, energy_with_very_big_jump);
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