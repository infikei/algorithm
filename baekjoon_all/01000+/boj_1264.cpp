#include <iostream>
#include <string>
using namespace std;

char aeiou[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    while (true) {
        string input;
        getline(cin, input);
        if (input == "#") {
            break;
        }

        int input_sz = input.length();
        int cnt = 0;
        for (int i = 0; i < input_sz; i++) {
            for (int j = 0; j < 10; j++) {
                if (input[i] == aeiou[j]) {
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}