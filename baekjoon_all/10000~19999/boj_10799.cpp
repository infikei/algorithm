#include <iostream>
#include <string>
using namespace std;

string input;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> input;

    int input_length = input.length();
    int now = 0;
    for (int i = 0; i < input_length; i++) {
        if (input[i] == '(') {
            if (input[i + 1] == ')') {
                ans += now;
            }
            else {
                now++;
            }
        }
        else {
            if (input[i - 1] == '(') {
                continue;
            }
            else {
                now--;
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}