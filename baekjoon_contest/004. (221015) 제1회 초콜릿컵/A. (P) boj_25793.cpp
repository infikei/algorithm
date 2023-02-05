#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll R, C;
        cin >> R >> C;

        ll b, c;

        if (R > C) {
            b = C;
            c = R - C;
        }
        else {
            b = R;
            c = C - R;
        }

        ll ans = (2 * b * b + 3 * b * c - 2) * b / 3;

        cout << (ans + min(R, C)) << ' ' << ans << '\n';
    }

    return 0;
}