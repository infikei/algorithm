#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    long long n, m, result5 = 0, result2 = 0;
    cin >> n >> m;

    // nCm = n! / m! / (n - m)! 인 것을 이용한다.
    // 즉, 1676번의 방법을 조금만 변형해서 해결할 수 있다.
    for (long long i = 5; i <= n; i *= 5) {
        result5 += n / i;
        result5 -= m / i;
        result5 -= (n - m) / i;
    }

    for (long long i = 2; i <= n; i *= 2) {
        result2 += n / i;
        result2 -= m / i;
        result2 -= (n - m) / i;
    }

    cout << min(result5, result2) << "\n";

    return 0;
}