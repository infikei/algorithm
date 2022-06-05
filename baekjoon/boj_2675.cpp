#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T, R, S_size;
    string S;
    char ch;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> R >> S;
        S_size = S.length();

        for (int i = 0; i < S_size; i++) {
            ch = S[i];
            for (int j = 0; j < R; j++) {
                cout << ch;
            }
        }
        cout << "\n";
    }

    return 0;
}