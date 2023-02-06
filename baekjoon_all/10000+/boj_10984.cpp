#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int sum0 = 0;
        float sum1 = 0;

        for (int n = 0; n < N; n++) {
            int C;
            float G;
            cin >> C >> G;

            sum0 += C;
            sum1 += C * G;
        }

        sum1 = sum1 / sum0;

        cout << sum0 << ' ';
        cout << fixed;
        cout.precision(1);
        cout << sum1 << '\n';
    }

    return 0;
}