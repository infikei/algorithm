#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int X, Y;
    cin >> X >> Y;

    if (X == 0) {
        int x[7] = {0, 1, 2, 2, 2, 1, 1};
        int y[7] = {1, 1, 1, 0, -1, -1, 0};

        cout << 7 << '\n';
        for (int i = 0; i < 7; i++) {
            cout << x[i] * Y << ' ' << y[i] * Y << '\n';
        }
    }
    else if (Y == 0) {
        int x[7] = {0, 1, 2, 2, 2, 1, 1};
        int y[7] = {1, 1, 1, 0, -1, -1, 0};

        cout << 7 << '\n';
        for (int i = 0; i < 7; i++) {
            cout << x[i] * X << ' ' << y[i] * X << '\n';
        }
    }
    else if (X == Y) {
        int x[7] = {1, 2, 3, 2, 1, 0, 1};
        int y[7] = {1, 0, -1, -2, -3, -2, -1};

        cout << 7 << '\n';
        for (int i = 0; i < 7; i++) {
            cout << x[i] * X << ' ' << y[i] * X << '\n';
        }
    }
    else {
        int dx[15] = {1, 2, 2, -1, -1, -2, -2, 1, -1, 2, 2, 1, 1, -2, -1};
        int dy[15] = {2, -1, -1, -2, -2, 1, -1, 2, 2, 1, 1, -2, -2, -1, 2};

        int XX = max(X, Y), YY = min(X, Y);
        int a = 0, b = 0;

        cout << 15 << '\n';
        for (int i = 0; i < 15; i++) {
            if (dx[i] == 1) {
                a += YY;
            }
            else if (dx[i] == 2) {
                a += XX;
            }
            else if (dx[i] == -1) {
                a -= YY;
            }
            else {
                a -= XX;
            }
            if (dy[i] == 1) {
                b += YY;
            }
            else if (dy[i] == 2) {
                b += XX;
            }
            else if (dy[i] == -1) {
                b -= YY;
            }
            else {
                b -= XX;
            }
            cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}