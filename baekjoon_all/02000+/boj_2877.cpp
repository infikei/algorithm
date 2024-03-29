#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int K;
    cin >> K;
    K++;

    string ans = "";

    while (K > 1) {
        if (K % 2 == 0) {
            ans = '4' + ans;
        }
        else {
            ans = '7' + ans;
        }
        K /= 2;
    }

    cout << ans << '\n';

    return 0;
}