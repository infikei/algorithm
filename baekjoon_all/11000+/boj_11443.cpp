// Solve 2023-03-08
// Update 2023-08-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using matrixll = vector<vector<ll> >;

const ll MOD = 1000000007;
const int MATRIX_SIZE = 2;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE, 0));

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int idx = 0; idx < MATRIX_SIZE; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
                res[row][col] %= MOD;
            }
        }
    }

    return res;
}

matrixll calc_mat_power(matrixll a, ll b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE, 0));

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

    ll n;
    cin >> n;

    matrixll mat = {
        { 1, 1 },
        { 1, 0 }
    };

    if (!(n & 1)) n++;

    matrixll ans = calc_mat_power(mat, n);

    cout << (ans[1][0] + MOD - 1) % MOD << '\n';

    return 0;
}
