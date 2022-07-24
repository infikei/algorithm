#include <iostream>
using namespace std;

int values[21][21];
int visited[21] = {0};
int N, result = 10000;

int calculate_diff() {

    // 첫번째 팀의 능력치 계산
    int team1_value = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            continue;
        }
        for (int j = i + 1; j <= N; j++) {
            if (visited[j] == 0) {
                continue;
            }
            team1_value += values[i][j];
            team1_value += values[j][i];
        }
    }

    // 두번째 팀의 능력치 계산
    int team0_value = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1) {
            continue;
        }
        for (int j = i + 1; j <= N; j++) {
            if (visited[j] == 1) {
                continue;
            }
            team0_value += values[i][j];
            team0_value += values[j][i];
        }
    }

    // 두 팀의 능력치 차이를 return
    return max(team1_value - team0_value, team0_value - team1_value);
}

void dfs(int depth = 1, int pos = 1) {
    if (depth == N / 2) {
        result = min(result, calculate_diff());
        // 답이 0보다 작은 경우는 없으므로, 0이 나온다면 다른 경우를 더 이상 탐색하지 않고 탐색을 종료한다.
        if (result == 0) {
            return;
        }
    }
    else {
        for (int i = pos + 1; i <= N; i++) {
            visited[i] = 1;
            dfs(depth + 1, i);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> values[i][j];
        }
    }

    // 가능한 모든 경우를 탐색
    visited[1] = 1;
    dfs();

    // 출력
    cout << result << '\n';

    return 0;
}