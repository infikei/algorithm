// Solve 2023-03-12

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
ll mat_sz;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(mat_sz, vector<ll>(mat_sz, 0));
    for (int row = 0; row < mat_sz; row++) {
        for (int col = 0; col < mat_sz; col++) {
            for (int idx = 0; idx < mat_sz; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
            }
            res[row][col] %= MOD;
        }
    }
    return res;
}

matrixll calc_mat_power(matrixll a, ll b) {
    matrixll res(mat_sz, vector<ll>(mat_sz, 0));
    for (int i = 0; i < mat_sz; i++) {
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

    ll k, n;
    cin >> k >> n;
    mat_sz = k + 2;

    matrixll mat(mat_sz, vector<ll>(mat_sz, 0));
    for (int row = 0; row < mat_sz; row++) {
        for (int col = 0; col <= row; col++) {
            mat[row][col] = 1;
        }
    }

    mat = calc_mat_power(mat, n);
    cout << mat[mat_sz - 1][0] << '\n';

    return 0;
}
