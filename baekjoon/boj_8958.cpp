#include <iostream>
#include <string>
using namespace std;

int oxox(string &s) {
    int cumulative = 0;
    int score = 0;

    for (char &ch : s) {
        if (ch == 'O') {
            cumulative++;
            score += cumulative;
        }
        else {
            cumulative = 0;
        }
    }

    return score;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << oxox(s) << '\n';
    }

    return 0;
}