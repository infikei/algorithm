#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int A[2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            A[i] += x;
        }
    }

    if (A[0] >= A[1]) {
        cout << A[0] << '\n';
    }
    else {
        cout << A[1] << '\n';
    }

    return 0;
}