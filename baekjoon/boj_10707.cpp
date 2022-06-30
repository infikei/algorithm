#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;

    cout << min(A * P, max(B, B + (P - C) * D)) << "\n";

    return 0;
}