#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            sum += temp;
        }
        if (sum == 0) {
            cout << "D\n";
        }
        else if (sum == 1) {
            cout << "C\n";
        }
        else if (sum == 2) {
            cout << "B\n";
        }
        else if (sum == 3) {
            cout << "A\n";
        }
        else {
            cout << "E\n";
        }
    }

    return 0;
}