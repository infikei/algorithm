// Solve 2023-03-07
// Update 2023-03-08

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

const ll MOD = 1000000007;
const int MATRIX_SIZE = 2;

ll calc_gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return calc_gcd(b, a % b);
}

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE));
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            res[row][col] = 0;
            for (int idx = 0; idx < MATRIX_SIZE; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
                res[row][col] %= MOD;
            }
        }
    }
    return res;
}

matrixll calc_mat_power(matrixll a, ll b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        res[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            res = calc_mat_mul(res, a);
        }
        a = calc_mat_mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    FASTIO;

    ll n, m;
    cin >> n >> m;

    matrixll mat = {
        { 1, 1 },
        { 1, 0 }
    };

    matrixll ans = calc_mat_power(mat, calc_gcd(n, m));
    cout << ans[1][0] << '\n';

    return 0;
}