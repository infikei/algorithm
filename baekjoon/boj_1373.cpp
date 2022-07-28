#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    cin >> input;

    if (input.length() % 3 == 1) {
        input = "00" + input;
    }
    else if (input.length() % 3 == 2) {
        input = "0" + input;
    }

    int temp = 0;

    for (int i = 0; i < input.length(); i += 3) {
        temp += (input[i] - '0') * 4;
        temp += (input[i + 1] - '0') * 2;
        temp += (input[i + 2] - '0');
        cout << temp;
        temp = 0;
    }

    cout << '\n';

    return 0;
}