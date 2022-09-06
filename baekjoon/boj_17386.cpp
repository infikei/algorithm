#include <iostream>
using namespace std;

int ccw(long long x0, long long y0, long long x1, long long y1, long long x2, long long y2) {
    long long ccw_check = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);

    if (ccw_check > 0) {
        return 1;
    }
    else if (ccw_check == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    long long x[4], y[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    if (ccw(x[0], y[0], x[1], y[1], x[2], y[2]) + ccw(x[0], y[0], x[1], y[1], x[3], y[3]) == 0) {
        if (ccw(x[2], y[2], x[3], y[3], x[0], y[0]) + ccw(x[2], y[2], x[3], y[3], x[1], y[1]) == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}