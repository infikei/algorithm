#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;

    while (getline(cin, input)) {
        int input_sz = input.length();

        for (int i = 0; i < input_sz; i++) {
            if (input[i] != ' ') {
                cnt[input[i] - 'a']++;
            }
        }
    }

    int max_cnt = *max_element(cnt, cnt + 26);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == max_cnt) {
            char ch = 'a' + i;
            cout << ch;
        }
    }
    cout << '\n';

    return 0;
}