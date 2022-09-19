#include <iostream>
using namespace std;

int ans[6];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int x, y;
    cin >> x >> y;

    ans[0] = 100 - x;
    ans[1] = 100 - y;
    ans[2] = 100 - ans[0] - ans[1];
    ans[3] = ans[0] * ans[1];
    ans[4] = ans[3] / 100;
    ans[5] = ans[3] % 100;

    for (int i = 0; i < 6; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    cout << ans[2] + ans[4] << ' ';
    cout << ans[5];

    return 0;
}