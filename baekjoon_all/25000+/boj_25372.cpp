#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.length() >= 6 && s.length() <= 9) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}