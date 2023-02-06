#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input, output = "";
    cin >> input;

    int var_type = 0; // 초기 상태 (변수의 형식이 아직 정해지지 않음) : 0 / java 형식 : 1 / C++ 형식 : 2 / 에러 : 3
    int nextUpper = 0; // 글자가 '_'인 경우 1로 설정되며 다음 글자를 대문자로 변환하는 데 사용

    if (input[0] == '_' || input[input.length() - 1] == '_') {
        var_type = 3; // 맨 앞 글자 또는 맨 뒤 글자가 '_'이면 에러
    }
    else if (input[0] >= 'A' && input[0] <= 'Z') {
        var_type = 3; // 맨 앞 글자가 대문자면 에러
    }
    else {
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];

            if (c >= 'A' && c <= 'Z') {
                if (var_type == 0) {
                    var_type = 1; // 형식이 정해지지 않은 초기 상태에서 대문자를 입력받으면 C++ 형식으로 변경
                }
                else if (var_type == 2) {
                    var_type = 3; // 이미 C++ 형식으로 정해진 상태에서 대문자를 입력받으면 에러
                    break;
                }
                output += "_";
                output += c - 'A' + 'a';
            }
            else if (c == '_') {
                if (nextUpper == 1) {
                    var_type = 3; // 바로 전에 '_'를 입력받은 상태에서 '_'를 연속으로 입력받으면 에러
                    break;
                }
                if (var_type == 0) {
                    var_type = 2; // 형식이 정해지지 않은 초기 상태에서 '_'를 입력받으면 java 형식으로 변경
                }
                else if (var_type == 1) {
                    var_type = 3; // 이미 java 형식으로 정해진 상태에서 '_'를 입력받으면 에러
                    break;
                }
                nextUpper = 1;
            }
            else {
                if (var_type == 2 && nextUpper == 1) {
                    output += c - 'a' + 'A';
                    nextUpper = 0;
                }
                else {
                    output += c;
                }
            }
        }
    }

    if (var_type == 3) {
        cout << "Error!\n";
    }
    else {
        cout << output << '\n';
    }

    return 0;
}