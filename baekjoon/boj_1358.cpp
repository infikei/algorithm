#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int w, h, x, y, p, ans = 0;
    cin >> w >> h >> x >> y >> p;

    for (int i = 0; i < p; i++) {
        int px, py;
        cin >> px >> py;

        if (px < x) {
            if ((x - px) * (x - px) + (y + h / 2 - py) * (y + h / 2 - py) <= h * h / 4) {
                ans++;
            }
            else {
                continue;
            }
        }
        else if (px <= x + w) {
            if (y <= py && py <= y + h) {
                ans++;
            }
            else {
                continue;
            }
        }
        else {
            if ((x + w - px) * (x + w - px) + (y + h / 2 - py) * (y + h / 2 - py) <= h * h / 4) {
                ans++;
            }
            else {
                continue;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}