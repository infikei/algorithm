#include <iostream>
using namespace std;

int A, B, N, ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> A >> B >> N;

    int i = 0;

    while (true) {
        A = A % B;
        if (A == 0) {
            ans = 0;
            break;
        }
        i++;
        A *= 10;
        if (i == N) {
            ans = A / B;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}