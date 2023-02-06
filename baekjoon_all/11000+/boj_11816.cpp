#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string num;
    cin >> num;

    if (num[0] != '0') {
        // 10진수
        cout << num << '\n';
    }
    else if (num[1] != 'x') {
        // 8진수
        int ans = 0;
        for (int i = 1; i < (int)num.length(); i++) {
            ans *= 8;
            ans += (num[i] - '0');
        }
        cout << ans << '\n';
    }
    else {
        // 16진수
        int ans = 0;
        for (int i = 2; i < (int)num.length(); i++) {
            ans *= 16;
            if (num[i] >= '0' && num[i] <= '9') {
                ans += (num[i] - '0');
            }
            else {
                ans += (num[i] - 'a' + 10);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}