// Solve 2023-03-03
// Update 2024-04-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using matrixll = vector<vector<ll>>;

const ll MOD = 1e6;
const int MATRIX_SIZE = 2;

matrixll multiply_matrix(const matrixll &a, const matrixll &b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE, 0));

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int idx = 0; idx < MATRIX_SIZE; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
            }

            res[row][col] %= MOD;
        }
    }

    return res;
}

matrixll power_matrix(matrixll a, ll b) {
    matrixll res(MATRIX_SIZE, vector<ll>(MATRIX_SIZE, 0));

    for (int i = 0; i < MATRIX_SIZE; i++) {
        res[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            res = multiply_matrix(res, a);
        }

        a = multiply_matrix(a, a);
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

    matrixll res = power_matrix(mat, n);
    cout << res[1][0] << '\n';

    return 0;
}
