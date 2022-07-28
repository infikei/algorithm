#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input, output = "";
    cin >> input;

    int temp = input[0] - '0';
    output += '0' + (temp / 4);
    output += '0' + ((temp % 4) / 2);
    output += '0' + (temp % 2);
    output = to_string(stoi(output)); // 주어진 수가 0인 경우 예외처리를 위한 코드 ("000" -> "0")
    cout << output;
    output = "";

    for (int i = 1; i < input.length(); i++) {
        temp = input[i] - '0';
        output += '0' + (temp / 4);
        output += '0' + ((temp % 4) / 2);
        output += '0' + (temp % 2);
        cout << output;
        output = "";
    }

    cout << '\n';

    return 0;
}