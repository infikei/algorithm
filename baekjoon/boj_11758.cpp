#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ccw = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (ccw > 0) {
        cout << 1;
    }
    else if (ccw < 0) {
        cout << -1;
    }
    else {
        cout << 0;
    }
    cout << '\n';

    return 0;
}