#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << (10000 + a * 1000);
    }
    else if (a == b or a == c) {
        cout << (1000 + a * 100);
    }
    else if (b == c) {
        cout << (1000 + b * 100);
    }
    else {
        cout << (max(max(a, b), c) * 100);
    }
    cout << '\n';

    return 0;
}