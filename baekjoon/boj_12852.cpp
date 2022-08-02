#include <iostream>
using namespace std;

int DP_count[1000001];
int DP_next[1000001];
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    DP_count[1] = 0;

    for (int i = 2; i <= N; i++) {
        DP_count[i] = DP_count[i - 1] + 1;
        DP_next[i] = i - 1;
        if (i % 2 == 0) {
            if (DP_count[i / 2] + 1 < DP_count[i]) {
                DP_count[i] = DP_count[i / 2] + 1;
                DP_next[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (DP_count[i / 3] + 1 < DP_count[i]) {
                DP_count[i] = DP_count[i / 3] + 1;
                DP_next[i] = i / 3;
            }
        }
    }

    cout << DP_count[N] << '\n';
    int now = N;
    for (int i = 0; i <= DP_count[N]; i++) {
        cout << now << ' ';
        now = DP_next[now];
    }
    cout << '\n';

    return 0;
}