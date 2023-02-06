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

    int ccw012 = ccw(x[0], y[0], x[1], y[1], x[2], y[2]);
    int ccw013 = ccw(x[0], y[0], x[1], y[1], x[3], y[3]);
    int ccw230 = ccw(x[2], y[2], x[3], y[3], x[0], y[0]);
    int ccw231 = ccw(x[2], y[2], x[3], y[3], x[1], y[1]);

    if (ccw012 * ccw013 == 0) {
        if (ccw230 * ccw231 == 0) {
            // 네 점이 모두 한 직선 위에 있는 경우에는 ccw 값이 모두 0이 나오게 되어 판별이 힘들다.
            // 따라서 직선 외부의 점 (x5, y5)를 하나 더 지정해서 ccw 알고리즘을 사용하는 방식으로 문제를 해결했다.

            // 4개의 점 중 하나의 점을 y축으로 +1만큼 이동시킨 점으로 5번째 점을 정했다.
            // 그런데 만약 y축과 평행한 직선일 경우에는 5번째 점 또한 같은 직선 위에 있게 되므로
            // y축이 아니라 x축으로 +1만큼 이동시킨 점으로 다시 정했다.
            long long x5 = x[0];
            long long y5 = y[0] + 1;
            if (x[0] == x[1]) {
                x5++;
                y5--;
            }

            int ccw520 = ccw(x5, y5, x[2], y[2], x[0], y[0]);
            int ccw521 = ccw(x5, y5, x[2], y[2], x[1], y[1]);
            int ccw530 = ccw(x5, y5, x[3], y[3], x[0], y[0]);
            int ccw531 = ccw(x5, y5, x[3], y[3], x[1], y[1]);

            if (ccw520 == ccw521) {
                if (ccw530 == ccw531) {
                    if (ccw520 == ccw530) {
                        cout << 0;
                    }
                    else {
                        cout << 1;
                    }
                }
                else {
                    cout << 1;
                }
            }
            else {
                cout << 1;
            }
        }
        else if (ccw230 == ccw231) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    else if (ccw230 * ccw231 == 0) {
        if (ccw012 == ccw013) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    else if (ccw012 == ccw013) {
        cout << 0;
    }
    else {
        if (ccw230 == ccw231) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << '\n';

    return 0;
}