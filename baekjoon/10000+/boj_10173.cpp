#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;

    while (true) {
        getline(cin, input);

        if (input == "EOI") {
            break;
        }

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.find("nemo") != -1) {
            cout << "Found" << '\n';
        }
        else {
            cout << "Missing" << '\n';
        }
    }

    return 0;
}