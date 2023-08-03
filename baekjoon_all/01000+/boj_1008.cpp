// Solve 2021-12-18
// Update 2023-08-02

#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    // cout.precision(n);
    // 해당 코드 이후 출력 시 실수 전체 자리수가 n자리로 표현된다.
    // 기본값은 6자리로 설정이 되어있는 듯 하다.

    // cout << fixed; cout.precision(n);
    // 해당 코드 이후 출력 시 소수점 아래 자리수가 n자리로 표현된다.
    // 이를 해제하려면 cout.unsetf(ios::fixed); 를 수행한다.
    // 반대로 cout << fixed; 는 cout.setf(ios::fixed); 와 동일하다.

    // 또는 iomanip을 include하면 다음 코드도 사용가능하다.
    // cout << fixed << setprecision(n);

    cout << fixed;
    cout.precision(12);

    cout << a / b << '\n';

    return 0;
}
