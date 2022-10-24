#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        bool check[26] = {false};
        for (char ch : S) {
            check[ch - 'A'] = true;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (!check[i]) {
                ans += i + 65;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}