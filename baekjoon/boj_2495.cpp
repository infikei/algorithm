#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 3; i++) {
        string S;
        cin >> S;

        int ans = 1, cnt = 1;

        for (int j = 1; j < 8; j++) {
            if (S[j] == S[j - 1]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}