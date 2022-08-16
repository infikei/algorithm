#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b;
    cin >> a >> b;

    double power = a * (100 - b) / 100;

    if (power >= 100) {
        cout << 0 << '\n';
    }
    else {
        cout << 1 << '\n';
    }

    return 0;
}