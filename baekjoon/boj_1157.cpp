#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    int input_count[26] = {0};

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if ('a' <= input[i] && input[i] <= 'z') {
            input_count[input[i] - 'a']++;
        } else {
            input_count[input[i] - 'A']++;
        }
    }

    int max = *max_element(input_count, input_count + 26);
    int ans_index = -1;
    for (int i = 0; i < 26; i++) {
        if (input_count[i] == max) {
            if (ans_index == -1) {
                ans_index = i;
            } else {
                ans_index = -2;
                break;
            }
        }
    }

    if (ans_index == -2) {
        cout << "?\n";
    } else {
        char ans_ch = 'A' + ans_index;
        cout << ans_ch << '\n';
    }

    return 0;
}