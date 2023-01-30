#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, A, S[51];
    cin >> N >> A;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    double d_lower = 0, d_upper = 1;
    bool possible = true;

    if (N >= 1) {
        if (A > S[1]) {
            possible = false;
        }
        else {
            double now = S[1] - A;
            d_lower = now;
            d_upper = now + 1;

            for (int i = 2; i <= N; i++) {
                if (S[i - 1] > S[i]) {
                    possible = false;
                    break;
                }

                now = S[i] - A;
                d_lower = max(d_lower, now / i);
                now = S[i] - A + 1;
                d_upper = min(d_upper, now / i);

                if (d_lower >= d_upper) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (possible) {
        cout << fixed;
        cout.precision(12);
        cout << d_lower << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}