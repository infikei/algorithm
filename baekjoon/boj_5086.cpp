#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b;

    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (a < b && b % a == 0) {
            cout << "factor\n";
        }
        else if (a > b && a % b == 0) {
            cout << "multiple\n";
        }
        else {
            cout << "neither\n";
        }
    }

    return 0;
}