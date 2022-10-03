#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, P;
    cin >> N >> P;

    int ans = P;

    if (N >= 5) {
        ans = min(ans, P - 500);
    }
    if (N >= 10) {
        ans = min(ans, (int)(P * 0.9));
    }
    if (N >= 15) {
        ans = min(ans, P - 2000);
    }
    if (N >= 20) {
        ans = min(ans, (int)(P * 0.75));
    }

    ans = max(ans, 0);
    cout << ans << '\n';

    return 0;
}