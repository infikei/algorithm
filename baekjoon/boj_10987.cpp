#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S;
    cin >> S;

    int cnt = 0;
    char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};

    for (char ch : S) {
        for (int i = 0; i < 5; i++) {
            if (ch == aeiou[i]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}