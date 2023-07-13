// Solve 2023-07-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using matrixll = vector<vector<ll> >;

const ll MOD = 1000000007;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b, const int n) {
    matrixll res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }

    return res;
}

matrixll calc_mat_power(matrixll a, const int n, int k) {
    matrixll res(n, vector<ll>(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (k > 0) {
        if (k & 1) {
            res = calc_mat_mul(res, a, n);
        }
        a = calc_mat_mul(a, a, n);
        k >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    matrixll mat(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    mat = calc_mat_power(mat, n, k);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += mat[i][j];
        }
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
