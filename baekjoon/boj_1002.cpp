#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    int x1, y1, r1, x2, y2, r2, ans;

    for (int t = 0; t < T; t++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            ans = -1;
        }
        else {
            double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            int d1_min = abs(r1 - r2);
            int d1_max = r1 + r2;

            if (d < d1_min || d > d1_max) {
                ans = 0;
            }
            else if (d == d1_min || d == d1_max) {
                ans = 1;
            }
            else {
                ans = 2;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}