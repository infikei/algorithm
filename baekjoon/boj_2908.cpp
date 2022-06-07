#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string a, b;
    cin >> a >> b;

    for (int i = 2; i >= 0; i--) {
        if (a[i] > b[i]) {
            cout << a[2] << a[1] << a[0];
            break;
        }
        else if (a[i] < b[i]) {
            cout << b[2] << b[1] << b[0];
            break;
        }
    }

    return 0;
}