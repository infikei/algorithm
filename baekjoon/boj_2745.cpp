#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    int n = 0, b;
    cin >> input >> b;

    for (int i = 0; i < input.length(); i++) {
        n *= b;
        if (input[i] > '9') {
            n += input[i] - 'A' + 10;
        }
        else {
            n += input[i] - '0';
        }
    }

    cout << n << "\n";

    return 0;
}