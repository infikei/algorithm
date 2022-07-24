#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    cin >> input;

    int result = 0, temp = 0, plusminus = 0;
    char ch;

    for (int i = 0; i < input.length(); i++) {
        ch = input[i];
        if (ch == '+') {
            if (plusminus == 0) {
                result += temp;
            }
            else {
                result -= temp;
            }
            temp = 0;
        }
        else if (ch == '-') {
            if (plusminus == 0) {
                result += temp;
                plusminus = 1;
            }
            else {
                result -= temp;
            }
            temp = 0;
        }
        else {
            temp *= 10;
            temp += ch - '0';
        }
    }

    if (plusminus == 0) {
        result += temp;
    }
    else {
        result -= temp;
    }

    cout << result << '\n';

    return 0;
}