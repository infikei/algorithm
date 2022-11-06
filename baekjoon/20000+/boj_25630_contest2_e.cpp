#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, cnt = 0;
    string S;

    cin >> N >> S;

    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - 1 - i]) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}