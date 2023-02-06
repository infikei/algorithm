#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int cntA = 0, cntB = 0;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        if (A > B) {
            cntA++;
        }
        else if (A < B) {
            cntB++;
        }
    }

    cout << cntA << ' ' << cntB << '\n';

    return 0;
}