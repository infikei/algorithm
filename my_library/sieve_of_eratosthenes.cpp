// 에라토스테네스의 체를 이용하여 어떤 수가 소수인지 아닌지를 판별한다.

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10001;

int main() {
    vector<bool> primes(MAX_SIZE, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (primes[i]) {
            for (int j = i + i; j < MAX_SIZE; j += i) {
                primes[j] = false;
            }
        }
    }

    return 0;
}