// 어떤 수가 소수(prime)인지 아닌지를 판별한다.

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int k) {
    if (k < 2) {
        return false;
    }

    int i_end = sqrt(k);
    for (int i = 2; i <= i_end; i++) {
        if (k % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "수를 입력하세요 : ";
    int n;
    cin >> n;

    if (is_prime(n)) {
        cout << n << "은 소수이다.\n";
    }
    else {
        cout << n << "은 소수가 아니다.\n";
    }

    return 0;
}