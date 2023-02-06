#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, change = 0;
    cin >> N;

    string ans = "";

    if (N == 0) {
        ans = "0";
    }

    while (N != 0) {
        if (N % 2 == 0) {
            ans = "0" + ans;
        }
        else {
            ans = "1" + ans;
            if (change == 0) {
                N = N - 1;
            }
            else {
                N = N + 1;
            }
        }

        N = N / 2;
        change = 1 - change;
    }

    cout << ans << '\n';

    return 0;
}