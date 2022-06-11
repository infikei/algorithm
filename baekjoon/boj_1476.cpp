#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int E, S, M, ans;
    cin >> E >> S >> M;
    ans = S;

    while (ans <= 7980) {
        if (ans % 15 == E % 15 && ans % 19 == M % 19) {
            cout << ans << "\n";
            break;
        }
        ans += 28;
    }

    return 0;
}