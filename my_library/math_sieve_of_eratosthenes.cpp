// 에라토스테네스의 체를 이용하여 어떤 수가 소수인지 아닌지를 판별한다.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_SIZE = 10001;

int main() {
    FASTIO;

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