#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    while (true) {
        int x;
        cin >> x;

        if (x == 0) {
            break;
        }

        if (x % N == 0) {
            cout << x << " is a multiple of " << N << ".\n";
        }
        else {
            cout << x << " is NOT a multiple of " << N << ".\n";
        }
    }

    return 0;
}