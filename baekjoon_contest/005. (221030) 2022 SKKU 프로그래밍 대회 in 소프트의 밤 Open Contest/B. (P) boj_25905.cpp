#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    double P[10];
    for (int i = 0; i < 10; i++) {
        cin >> P[i];
    }

    sort(P, P + 10);

    double ans = 1;

    for (int i = 1; i < 10; i++) {
        ans = ans * 10 * P[i] / i;
    }

    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';

    return 0;
}