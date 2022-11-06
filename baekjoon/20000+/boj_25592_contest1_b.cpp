#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    int i = 1;
    int now = 0;

    while (true) {
        now += i;
        if (N < now) {
            if (i % 2 == 0) {
                cout << 0 << '\n';
            }
            else {
                cout << now - N << '\n';
            }
            break;
        }

        i++;
    }

    return 0;
}