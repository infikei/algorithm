#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int count[42] = {0};
    int x = 0;
    for (int i = 0; i < 10; i++) {
        cin >> x;
        count[x % 42]++;
    }

    int ans = 0;
    for (int i : count) {
        if (i > 0) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}