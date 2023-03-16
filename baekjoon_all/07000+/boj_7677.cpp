// Solve 2023-03-10

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
using matrix = vector<vector<int> >;

const ll MOD = 10000;
const int MATRIX_SIZE = 2;

matrix calc_mat_mul(const matrix &a, const matrix &b) {
    matrix res(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 0));
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int idx = 0; idx < MATRIX_SIZE; idx++) {
                res[row][col] += a[row][idx] * b[idx][col];
            }
            res[row][col] %= MOD;
        }
    }
    return res;
}

matrix calc_mat_power(matrix a, int b) {
    matrix res(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 0));
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

    matrix mat = {
        { 1, 1 },
        { 1, 0 }
    };

    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }

        matrix ans = calc_mat_power(mat, n);
        cout << ans[1][0] << '\n';
    }

    return 0;
}