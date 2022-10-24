#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int K, D1, D2;
    cin >> K >> D1 >> D2;

    double ans = pow(K, 2) - pow((double)(D1 - D2) / 2, 2);

    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';

    return 0;
}