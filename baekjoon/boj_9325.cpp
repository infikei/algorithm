#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int S, N;
        cin >> S >> N;

        for (int n = 0; n < N; n++) {
            int Q, P;
            cin >> Q >> P;

            S += (Q * P);
        }

        cout << S << '\n';
    }

    return 0;
}