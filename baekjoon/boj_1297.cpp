#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    long long a, b;
    cin >> a >> b;

    long long ans;

    if (a <= b) {
        ans = (a + b) * (b - a + 1) / 2;
    }
    else {
        ans = (a + b) * (a - b + 1) / 2;
    }

    cout << ans << "\n";

    return 0;
}