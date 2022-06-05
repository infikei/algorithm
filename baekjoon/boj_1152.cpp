#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    getline(cin, input);
    int input_length = input.length();

    // 단어의 개수 = 공백의 개수 + 1
    int word = 0;
    for (int i = 0; i < input_length; i++) {
        if (input[i] == ' ') {
            word++;
        }
    }
    word++;

    // 문장의 시작 또는 끝이 공백인 경우 처리
    if (input[0] == ' ')
        word--;
    if (input[input_length - 1] == ' ')
        word--;

    cout << word << "\n";

    return 0;
}