#include <iostream>
#include <string>
using namespace std;

string input[5], ans = "";
int input_size[5];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 5; i++) {
        cin >> input[i];
        input_size[i] = input[i].length();
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < input_size[j]) {
                ans += input[j][i];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}