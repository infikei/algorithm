#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    while (true) {
        int N;
        cin >> N;

        if (N == 0) {
            break;
        }

        int x;
        cin >> x;

        for (int i = 1; i < N; i++) {
            int y;
            cin >> y;

            if (x == y) {
                continue;
            }

            cout << x << ' ';
            x = y;
        }

        cout << x << " $\n";
    }

    return 0;
}