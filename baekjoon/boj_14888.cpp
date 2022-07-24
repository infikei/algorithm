#include <iostream>
using namespace std;

int numbers[11];
int operators[4];
int used_operators[4];
int N, max_result, min_result;

void initialize() {
    int current_operator = 0;
    int current_value = numbers[0];

    for (int i = 1; i < N; i++) {
        while (used_operators[current_operator] >= operators[current_operator]) {
            current_operator++;
        }
        if (current_operator == 0) {
            current_value += numbers[i];
        }
        else if (current_operator == 1) {
            current_value -= numbers[i];
        }
        else if (current_operator == 2) {
            current_value *= numbers[i];
        }
        else {
            current_value /= numbers[i];
        }
        used_operators[current_operator]++;
    }

    max_result = min_result = current_value;
}

void dfs(int current_value = numbers[0], int depth = 1) {
    if (depth >= N) {
        if (current_value > max_result) {
            max_result = current_value;
        }
        if (current_value < min_result) {
            min_result = current_value;
        }
    }
    else {
        if (operators[0] > 0) {
            operators[0]--;
            dfs(current_value + numbers[depth], depth + 1);
            operators[0]++;
        }
        if (operators[1] > 0) {
            operators[1]--;
            dfs(current_value - numbers[depth], depth + 1);
            operators[1]++;
        }
        if (operators[2] > 0) {
            operators[2]--;
            dfs(current_value * numbers[depth], depth + 1);
            operators[2]++;
        }
        if (operators[3] > 0) {
            operators[3]--;
            dfs(current_value / numbers[depth], depth + 1);
            operators[3]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    // 초기값 세팅
    for (int i = 0; i < 4; i++) {
        used_operators[i] = 0;
    }
    initialize();

    // 가능한 모든 경우에 대해 계산 실행
    for (int i = 0; i < 4; i++) {
        used_operators[i] = 0;
    }
    dfs();

    // 결과 출력
    cout << max_result << '\n';
    cout << min_result << '\n';

    return 0;
}