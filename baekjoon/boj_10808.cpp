#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S;
    cin >> S;

    int arr[26] = {0};

    for (int i = 0; i < S.length(); i++) {
        arr[S[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}