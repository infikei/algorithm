#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        a *= a;
        b *= b;
        c *= c;

        if (a + b == c || a + c == b || b + c == a)
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}