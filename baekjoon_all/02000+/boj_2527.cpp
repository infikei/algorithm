#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T = 4;

    for (int t = 0; t < T; t++) {
        int x[4], y[4];

        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
        }

        int x_check, y_check;

        if (x[1] < x[2] || x[3] < x[0]) {
            x_check = 0;
        }
        else if (x[1] == x[2] || x[3] == x[0]) {
            x_check = 1;
        }
        else {
            x_check = 2;
        }

        if (y[1] < y[2] || y[3] < y[0]) {
            y_check = 0;
        }
        else if (y[1] == y[2] || y[3] == y[0]) {
            y_check = 1;
        }
        else {
            y_check = 2;
        }

        if (x_check == 2 && y_check == 2) {
            cout << 'a';
        }
        else if (x_check + y_check == 3) {
            cout << 'b';
        }
        else if (x_check == 1 && y_check == 1) {
            cout << 'c';
        }
        else {
            cout << 'd';
        }
        cout << '\n';
    }

    return 0;
}