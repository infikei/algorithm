// 어떤 수가 소수(prime)인지 아닌지를 판별한다.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

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
    FASTIO;

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