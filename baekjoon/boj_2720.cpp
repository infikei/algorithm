#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    int arr[4] = {25, 10, 5, 1};

    for (int t = 0; t < T; t++) {
        int C;
        cin >> C;

        for (int i = 0; i < 4; i++) {
            cout << (C / arr[i]) << ' ';
            C = (C % arr[i]);
        }

        cout << '\n';
    }

    return 0;
}