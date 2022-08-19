#include <iostream>
#include <cmath>
using namespace std;

bool MEMO[10001];
int P, p2, M;

void initialize_MEMO() {
    for (int i = 1; i <= 10000; i++) {
        MEMO[i] = false;
    }
}

bool is_prime_int(int a) {
    if (a == 1) {
        return false;
    }

    double sqrt_a = sqrt(a);

    for (int i = 2; i <= sqrt_a; i++) {
        if (a % i == 0) {
            return false;
        }
    }

    return true;
}

int calc_to_check_happy_int(int a) {
    int result = 0;
    while (a > 0) {
        result += (a % 10) * (a % 10);
        a = a / 10;
    }

    return result;
}

bool is_happy_int(int a) {
    if (a == 1) {
        return true;
    }

    initialize_MEMO();
    MEMO[a] = true;
    while (true) {
        a = calc_to_check_happy_int(a);
        if (a == 1) {
            return true;
        }
        else if (MEMO[a]) {
            return false;
        }
        else {
            MEMO[a] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> P;
    for (int p = 1; p <= P; p++) {
        cin >> p2 >> M;
        cout << p2 << ' ' << M << ' ';

        if (is_prime_int(M) && is_happy_int(M)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}