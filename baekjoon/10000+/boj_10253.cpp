#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void calc(long long& a, long long& b) {
    long long x = b / a + 1;
    long long GCD = gcd(x, b);
    a = (a * x - b) / GCD;
    b = b / GCD * x;

    GCD = gcd(b, a);
    a /= GCD;
    b /= GCD;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long a, b;
        cin >> a >> b;

        while (a != 1) {
            calc(a, b);
        }

        cout << b << '\n';
    }

    return 0;
}