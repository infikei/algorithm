#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string s;
    cin >> s;

    int N, cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s1;
        cin >> s1;

        if (s == s1) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}