#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    string input;
    cin >> input;

    int input_size = input.size();
    int count[26] = {0};

    for (int i = 0; i < input_size; i++) {
        if ('a' <= input[i] && input[i] <= 'z') {
            count[input[i] - 'a']++;
        } else {
            count[input[i] - 'A']++;
        }
    }

    int max = *max_element(count, count+26);
    int ans = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] == max) {
            if (ans == -1) {
                ans = i;
            } else {
                ans = -2;
                break;
            }
        }
    }

    if (ans == -2) {
        cout << "?\n";
    } else {
        char answer = 'A' + ans;
        cout << answer << "\n";
    }

    return 0;
}