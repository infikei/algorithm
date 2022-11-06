#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    string S;
    cin >> N >> S;

    int s = 0, t = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 's') {
            s++;
        }
        else {
            t++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (s == t) {
            cout << S.substr(i, N - i) << '\n';
            break;
        }

        if (S[i] == 's') {
            s--;
        }
        else {
            t--;
        }
    }

    return 0;
}