#include <iostream>
#include <string>
using namespace std;

int N;
string S[20];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    bool b1 = (S[0] < S[1]);
    bool b2 = true;

    for (int i = 1; i < N - 1; i++) {
        if (b1 != (S[i] < S[i + 1])) {
            b2 = false;
            break;
        }
    }

    if (!b2) {
        cout << "NEITHER\n";
    }
    else if (b1) {
        cout << "INCREASING\n";
    }
    else {
        cout << "DECREASING\n";
    }

    return 0;
}