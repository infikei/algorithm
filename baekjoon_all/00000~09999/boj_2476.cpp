#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c, temp = 0;
        cin >> a >> b >> c;

        if (a == b) {
            if (b == c) {
                temp = (10 + a) * 1000;
            }
            else {
                temp = (10 + a) * 100;
            }
        }
        else if (a == c || b == c) {
            temp = (10 + c) * 100;
        }
        else {
            temp = max(a, max(b, c)) * 100;
        }

        if (temp > ans) {
            ans = temp;
        }
    }

    cout << ans << '\n';

    return 0;
}