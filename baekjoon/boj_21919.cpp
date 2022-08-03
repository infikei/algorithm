#include <iostream>
#include <cmath>
using namespace std;

int N, A[10000];
long long ans;
bool exist_prime;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    ans = 1;
    exist_prime = false;

    for (int i = 0; i < N; i++) {
        if (ans % A[i] != 0 && isPrime(A[i])) {
            ans *= A[i];
            exist_prime = true;
        }
    }
}

void print() {
    if (exist_prime) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    print();

    return 0;
}