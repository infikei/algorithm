#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int MM, DD;
    cin >> MM >> DD;
    int x = MM * 100 + DD;

    if (x < 218) {
        cout << "Before\n";
    }
    else if (x > 218) {
        cout << "After\n";
    }
    else {
        cout << "Special\n";
    }

    return 0;
}