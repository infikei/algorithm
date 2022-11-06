#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int i = 1;

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (i > 1) {
            cout << '\n';
        }
        cout << "Triangle #" << i << '\n';
        i++;

        if (c == -1) {
            double ans = sqrt(pow(a, 2) + pow(b, 2));
            cout << fixed;
            cout.precision(3);
            cout << "c = " << ans << '\n';
        }
        else if (a == -1) {
            if (b >= c) {
                cout << "Impossible.\n";
                continue;
            }
            double ans = sqrt(pow(c, 2) - pow(b, 2));
            cout << fixed;
            cout.precision(3);
            cout << "a = " << ans << '\n';
        }
        else {
            if (a >= c) {
                cout << "Impossible.\n";
                continue;
            }
            double ans = sqrt(pow(c, 2) - pow(a, 2));
            cout << fixed;
            cout.precision(3);
            cout << "b = " << ans << '\n';
        }
    }

    return 0;
}