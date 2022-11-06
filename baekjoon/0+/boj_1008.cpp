#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    // cout.precision(n); 코드
    // - 해당 코드 이후 출력 시 실수 전체 자리수를 n자리로 표현하도록 설정한다.
    // - 기본값은 6자리로 설정이 되어있는 듯 하다.

    // cout << fixed;를 설정하고 나서 cout.precision(n); 코드
    // - 해당 코드 이후 출력 시 소수점 아래 자리수를 n자리로 표현하도록 설정한다.

    // cout << fixed;을 해제하려면 cout.unsetf(ios::fixed); 코드를 사용한다.
    // 반대로 cout << fixed; 코드는 cout.setf(ios::fixed); 코드와 동일하다.

    cout << fixed;
    cout.precision(12);
    cout << a / b << endl;

    return 0;
}