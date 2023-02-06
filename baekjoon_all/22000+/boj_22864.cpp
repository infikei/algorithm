#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int fatigue = 0, done = 0;

    for (int hour = 0; hour < 24; hour++) {
        if (fatigue + A <= M) {
            fatigue += A;
            done += B;
        }
        else {
            fatigue -= C;
        }

        if (fatigue < 0) {
            fatigue = 0;
        }
    }

    cout << done << '\n';

    return 0;
}