#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int A[10], B[10];
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> B[i];
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) {
            ans++;
        }
        else if (A[i] < B[i]) {
            ans--;
        }
    }

    if (ans > 0) {
        cout << 'A';
    }
    else if (ans < 0) {
        cout << 'B';
    }
    else {
        cout << 'D';
    }
    cout << '\n';

    return 0;
}