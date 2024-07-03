#include <iostream>
using namespace std;

int N, X, voices[101], ans = 1;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> voices[i];
    }

    int min_cnt = 87654321;
    for (int i = 1; i <= N; i++) {
        int now_cnt = (voices[i] - X + N - i + 1) / N;
        if (now_cnt <= 0) {
            ans = i;
            break;
        }
        if (min_cnt > now_cnt) {
            ans = i;
            min_cnt = now_cnt;
        }
    }

    cout << ans << '\n';

    return 0;
}