#include <iostream>
using namespace std;

int solve(int n) {
    if (n == 0) {
        return 0;
    }

    int prepre = 0, pre = 0, res = 1;

    for (int i = 2; i <= n; i++) {
        prepre = pre;
        pre = res;
        res = (pre + prepre) % 1000000007;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}