#include <iostream>
using namespace std;
typedef long long ll;

int N;
ll T[36];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    T[0] = 1;
    for (int n = 1; n <= N; n++) {
        for (int i = 0; i < n / 2; i++) {
            T[n] += T[i] * T[n - 1 - i] * 2;
        }
        if (n % 2 == 1) {
            T[n] += T[n / 2] * T[n / 2];
        }
    }

    cout << T[N] << '\n';

    return 0;
}