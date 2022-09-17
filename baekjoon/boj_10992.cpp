#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    // 첫째 줄
    for (int i = 0; i < N - 1; i++) {
        cout << ' ';
    }
    cout << '*' << '\n';

    // 중간 줄
    for (int row = 2; row < N; row++) {
        for (int i = 0; i < N - row; i++) {
            cout << ' ';
        }
        cout << '*';
        for (int i = 0; i < 2 * row - 3; i++) {
            cout << ' ';
        }
        cout << '*' << '\n';
    }

    // 마지막 줄
    if (N > 1) {
        for (int i = 0; i < 2 * N - 1; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}