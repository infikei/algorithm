#include <iostream>
using namespace std;

int C, N;
const int SIZE = 1001;
int memo[SIZE]; // index : 고객, value : 비용

void initialize_memo() {
    // memo 배열을 9999로 초기화
    // (문제에서 주어진 100을 넘어서는 아무 값으로 설정하면 된다.)
    for (int i = 1; i < SIZE; i++) {
        memo[i] = 7654321;
    }

    // memo 배열에 입력값 넣기
    // (같은 수의 고객에 대한 비용이 2개 이상으로 주어진 경우 그 중 최솟값으로 저장한다.)
    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;
        memo[y] = min(memo[y], x);
    }

    // memo 배열 오름차순으로 정렬
    // (배열 앞쪽의 값이 배열 뒤쪽의 값보다 더 클 경우 배열 앞쪽의 값을 배열 뒤쪽의 값으로 덮어쓴다.)
    // (따라서 마지막에서 처음의 방향으로 값을 검사하며 다시 저장해야 한다.)
    int now = 7654321;
    for (int i = SIZE - 1; i >= 1; i--) {
        if (memo[i] > now) {
            memo[i] = now;
        }
        else {
            now = memo[i];
        }
    }

    // memo 배열 가장 앞쪽이 0일 경우, 이에 대한 처리
    // (예를 들어 index=3의 값이 5이고 index=1,2의 값이 0이면 index=1,2의 값도 5로 저장해준다.)
    int ini = 1;
    for (int i = 1; i < SIZE; i++) {
        if (memo[i] > 0) {
            ini = i;
            break;
        }
    }
    for (int i = 1; i < ini; i++) {
        memo[i] = memo[ini];
    }

    // 이제 본격적으로 계산해준다. (DP)
    for (int i = 2; i < SIZE; i++) {
        int i_half = i / 2;
        for (int j = 1; j <= i_half; j++) {
            memo[i] = min(memo[i], memo[j] + memo[i - j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> C >> N;

    initialize_memo();

    cout << memo[C] << '\n';

    return 0;
}