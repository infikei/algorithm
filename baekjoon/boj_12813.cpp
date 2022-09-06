#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string A, B;
    cin >> A >> B;

    int sz = 100000;

    for (int i = 0; i < sz; i++) {
        if (A[i] == '1' && B[i] == '1') {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << '\n';

    for (int i = 0; i < sz; i++) {
        if (A[i] == '1' || B[i] == '1') {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << '\n';

    for (int i = 0; i < sz; i++) {
        if (A[i] == B[i]) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << '\n';

    for (int i = 0; i < sz; i++) {
        if (A[i] == '1') {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << '\n';

    for (int i = 0; i < sz; i++) {
        if (B[i] == '1') {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << '\n';

    return 0;
}