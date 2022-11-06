#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int a, b, g;
    cin >> a;
    for (int i = 1; i < N; i++) {
        cin >> b;
        g = gcd(a, b);
        cout << a / g << '/' << b / g << '\n';
    }

    return 0;
}