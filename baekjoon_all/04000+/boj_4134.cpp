#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned int N) {
    if (N <= 1) {
        return false;
    }
    for (unsigned int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        unsigned int N;
        cin >> N;

        while (!isPrime(N)) {
            N++;
        }

        cout << N << '\n';
    }

    return 0;
}