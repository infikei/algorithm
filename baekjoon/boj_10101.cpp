#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180) {
        cout << "Error\n";
    }
    else {
        if (a == 60 && b == 60) {
            cout << "Equilateral\n";
        }
        else if (a == b || b == c || c == a) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}