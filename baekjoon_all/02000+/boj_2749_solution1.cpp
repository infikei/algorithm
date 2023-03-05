// Solve 2023-03-03
// Update 2023-03-05

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
using matrixll = vector<vector<ll> >;

const ll MOD = 1e6;

matrixll mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(2, vector<ll>(2));
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            res[row][col] = 0;
            for (int idx = 0; idx < 2; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
                res[row][col] %= MOD;
            }
        }
    }
    return res;
}

matrixll mat_power(matrixll a, ll b) {
    matrixll res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        res[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    FASTIO;

    matrixll m = {
        { 1, 1 },
        { 1, 0 }
    };

    ll n;
    cin >> n;

    matrixll ans = mat_power(m, n);
    cout << ans[0][1] << '\n';

    return 0;
}