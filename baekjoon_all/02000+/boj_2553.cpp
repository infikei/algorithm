// Solve 2023-02-08
// Update 2024-06-19

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll val = 1;

    for (int i = 2; i <= n; i++) {
        val *= i;

        while (val % 10 == 0) {
            val /= 10;
        }

        val %= 1000000; // 이것보다 작은 10의 거듭제곱으로 하면 n >= 15625 에서 오류가 생긴다.
    }

    val %= 10;
    cout << val << '\n';

    return 0;
}

// 테스트케이스 모음

// 15624
// 6

// 15625
// 4

// 15626
// 4

// 19999
// 8

// 20000
// 6
