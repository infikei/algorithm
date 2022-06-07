#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, ans = 0;
    cin >> N;

    string input;
    bool check[26];
    char temp, temp2;

    for (int n = 0; n < N; n++) {
        cin >> input;
        ans++;
        fill_n(check, 26, false);

        temp = input[0];
        for (int i = 1; i < input.length(); i++) {
            temp2 = input[i];
            if (temp != temp2) {
                if (check[temp2 - 'a']) {
                    ans--;
                    break;
                }
                else {
                    check[temp - 'a'] = true;
                    temp = temp2;
                }
            }
        }
    }

    cout << ans;

    return 0;
}