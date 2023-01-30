#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            sum += temp;
        }
        if (sum == 0) {
            cout << 'D';
        }
        else if (sum == 1) {
            cout << 'C';
        }
        else if (sum == 2) {
            cout << 'B';
        }
        else if (sum == 3) {
            cout << 'A';
        }
        else {
            cout << 'E';
        }
        cout << '\n';
    }

    return 0;
}