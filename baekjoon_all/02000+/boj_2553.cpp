// Solve 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

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

    return 0;
}