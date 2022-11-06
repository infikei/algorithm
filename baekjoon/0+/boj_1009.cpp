#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T, a, b, ans;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ans = 1;
        cin >> a >> b;
        a = (a - 1) % 10 + 1;
        b = (b - 1) % 4 + 1;
        while (b--) {
            ans *= a;
        }
        cout << (ans - 1) % 10 + 1 << '\n';
    }

    return 0;
}