#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int ans = 0, now = 0;

    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;

        now -= a;
        now += b;
        ans = max(ans, now);
    }

    cout << ans << '\n';

    return 0;
}