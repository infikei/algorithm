#include <iostream>
using namespace std;

int DP[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (DP[a][b][c] != 0) // 이미 DP에 저장된 값이라면 바로 반환한다.
        return DP[a][b][c];

    // 그렇지 않다면 계산해서 DP에 저장하고 그 값을 반환한다.
    if (a < b && b < c)
        DP[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return DP[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}