#include <iostream>
using namespace std;

int A[500000], N, X, cnt;
long long sum;
double avr;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> X;
}

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

bool disjoint(int a, int b) {
    return gcd(a, b) == 1;
}

void solve() {
    cnt = 0;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (disjoint(X, A[i])) {
            cnt++;
            sum += A[i];
        }
    }
    avr = (double)sum / cnt;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << avr << '\n';

    return 0;
}