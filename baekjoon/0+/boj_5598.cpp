#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string s;
    cin >> s;
    int s_sz = s.length();

    for (int i = 0; i < s_sz; i++) {
        if (s[i] >= 'D') {
            char ch = s[i] - 3;
            cout << ch;
        }
        else {
            char ch = s[i] + 23;
            cout << ch;
        }
    }
    cout << '\n';

    return 0;
}