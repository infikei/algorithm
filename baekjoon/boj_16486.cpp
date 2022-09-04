#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int d[2];
    for (int i = 0; i < 2; i++) {
        cin >> d[i];
    }

    cout << fixed;
    cout.precision(8);

    cout << 2 * (d[0] + (double)d[1] * 3.141592) << '\n';

    return 0;
}