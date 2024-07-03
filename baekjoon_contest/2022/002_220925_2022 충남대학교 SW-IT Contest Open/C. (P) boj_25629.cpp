#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a % 2 == 0) {
            cnt++;
        }
    }

    if (N / 2 == cnt) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}