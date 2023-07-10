// Solve 2023-07-09

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
    matrixll res(2, vector<ll>(2));

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= MOD;
        }
    }

    return res;
}

matrixll calc_mat_power(matrixll a, ll k) {
    matrixll res(2, vector<ll>(2));
    res = {
        { 1, 0 },
        { 0, 1 }
    };

    while (k > 0) {
        if (k & 1) {
            res = calc_mat_mul(res, a);
        }
        a = calc_mat_mul(a, a);
        k >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    matrixll mat = {
        { 1, 2 },
        { 1, 3 }
    };

    if (n & 1) {
        cout << 0 << '\n';
    }
    else {
        matrixll ans_mat = calc_mat_power(mat, (n >> 1) - 1);
        ll ans = ans_mat[0][0] * 3 + (ans_mat[0][1] << 2);
        ans %= MOD;
        cout << ans << '\n';
    }

    return 0;
}
