#include <iostream>
#include <string>
using namespace std;

string solve(const string& s) {
    int s_sz = s.length();
    int cnt[26] = {0};

    for (int i = 0; i < s_sz; i++) {
        cnt[s[i] - 'A']++;
    }

    string res_left = "";
    string res_right = "";
    int res_center = -1;

    for (int i = 0; i < 26; i++) {
        while (cnt[i] > 0) {
            if (cnt[i] == 1) {
                if (res_center == -1) {
                    res_center = i;
                    cnt[i]--;
                }
                else {
                    return "I'm Sorry Hansoo";
                }
            }
            else {
                res_left = res_left + (char)('A' + i);
                res_right = (char)('A' + i) + res_right;
                cnt[i] -= 2;
            }
        }
    }

    if (res_center == -1) {
        return res_left + res_right;
    }
    else {
        return res_left + (char)('A' + res_center) + res_right;
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    cin >> input;

    cout << solve(input) << '\n';

    return 0;
}