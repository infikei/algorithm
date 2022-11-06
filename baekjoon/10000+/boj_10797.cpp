#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, x, ans = 0;
    cin >> n;

    for (int i = 0; i < 5; i++) {
        cin >> x;
        if (n == x) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}