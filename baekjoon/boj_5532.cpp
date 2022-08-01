#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    A = (A - 1) / C + 1;
    B = (B - 1) / D + 1;

    cout << (A >= B ? L - A : L - B) << '\n';

    return 0;
}