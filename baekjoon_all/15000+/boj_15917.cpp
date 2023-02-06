// 2의 거듭제곱 판별 알고리즘

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int a;
        cin >> a;

        if ((a & (-a)) == a) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}