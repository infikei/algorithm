#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    cin >> input;

    int ans[26];
    fill_n(ans, 26, -1);

    for (int i = 0; i < input.size(); i++) {
        if (ans[input[i] - 'a'] == -1)
            ans[input[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}