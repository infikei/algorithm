#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // input
    int N;
    cin >> N;

    // initialize
    int cnt[10];
    for (int i = 0; i < 10; i++) {
        cnt[i] = 1;
    }

    // calculate
    for (int n = 2; n <= N; n++) {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                cnt[i] = (cnt[i] + cnt[j]) % 10007;
            }
        }
    }

    // print
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + cnt[i]) % 10007;
    }
    cout << ans << '\n';

    return 0;
}