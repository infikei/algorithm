#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int x[3], y[3];

    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    if ((x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]) == 0) {
        // 세 점이 한 직선 위에 위치할 경우, 만들 수 있는 평행사변형은 존재할 수 없다.
        cout << -1 << '\n';
    }
    else {
        // 주어진 세 점으로 만들 수 있는 삼각형의 세 변의 길이를 a, b, c라고 하자. (a >= b >= c)
        // 그러면 주어진 세 점으로 만들 수 있는 평행사변형의 둘레의 길이로 가능한 것은
        // 2a + 2b, 2a + 2c, 2b + 2c가 된다.
        // 따라서 우리가 구해야 할 답은 (2a + 2b) - (2b + 2c) = 2a - 2c이다.

        double len[3];
        len[0] = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
        len[1] = sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]));
        len[2] = sqrt((x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));

        sort(len, len + 3);
        cout << fixed;
        cout.precision(11);
        cout << 2 * (len[2] - len[0]) << '\n';
    }

    return 0;
}