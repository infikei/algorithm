#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;

    while (getline(cin, input)) {
        int input_sz = input.length();
        int cnt[4] = {0};

        for (int i = 0; i < input_sz; i++) {
            if (input[i] >= 'a') {
                // 소문자
                cnt[0]++;
            }
            else if (input[i] >= 'A') {
                // 대문자
                cnt[1]++;
            }
            else if (input[i] >= '0') {
                // 숫자
                cnt[2]++;
            }
            else {
                // 공백
                cnt[3]++;
            }
        }

        for (int i = 0; i < 4; i++) {
            cout << cnt[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}