#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int m, n;
    cin >> m >> n;

    int begin = sqrt(m - 1) / 1 + 1, end = sqrt(n) / 1;
    int min = begin * begin, sum = 0;
    for (int i = begin; i <= end; i++) {
        sum += i * i;
    }
    if (sum == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << sum << '\n';
        cout << min << '\n';
    }

    return 0;
}