#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    string S[51];
    string ans = "";

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < S[0].length(); i++) {
        char ch = S[0][i];
        bool same = true;
        for (int j = 1; j < N; j++) {
            if (S[j][i] != ch) {
                same = false;
                break;
            }
        }
        if (same) {
            ans += ch;
        }
        else {
            ans += '?';
        }
    }

    cout << ans;

    return 0;
}