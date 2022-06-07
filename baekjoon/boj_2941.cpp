#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    string input;
    cin >> input;

    int ans = input.length();

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '=') {
            if (i >= 2) {
                if (input[i - 2] == 'd' && input[i - 1] == 'z') {
                    ans -= 2;
                }
                else {
                    ans--;
                }
            }
            else {
                ans--;
            }
        }
        else if (input[i] == '-') {
            ans--;
        }
        else if (input[i] == 'j' && i >= 1) {
            if (input[i - 1] == 'l' || input[i - 1] == 'n') {
                ans--;
            }
        }
    }

    cout << ans;

    return 0;
}