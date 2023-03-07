// Solve 2022-10-22
// Update 2023-03-06

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MOD = 1000000007;

int calc_fibonacci(int k) {
    if (k == 0) {
        return 0;
    }

    int val[3] = { 0, 0, 1 };
    for (int i = 2; i <= k; i++) {
        val[0] = val[1];
        val[1] = val[2];
        val[2] = (val[0] + val[1]) % MOD;
    }
    return val[2];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    cout << calc_fibonacci(n) << '\n';

    return 0;
}