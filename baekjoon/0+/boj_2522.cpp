#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= N - i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}