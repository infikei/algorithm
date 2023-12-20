// Solve 2023-07-12
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using matrixll = vector<vector<ll>>;

const ll MOD = 1000000007;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    int n = SIZE(a);
    matrixll res(n, vector<ll>(n));

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int idx = 0; idx < n; idx++) {
                res[row][col] += a[row][idx] * b[idx][col];
                res[row][col] %= MOD;
            }
        }
    }

    return res;
}

matrixll calc_mat_power(matrixll a, int k) {
    int n = SIZE(a);
    matrixll res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

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

    int n, k;
    cin >> n >> k;

    matrixll mat(n, vector<ll>(n));

    for (vector<ll> &row : mat) {
        for (ll &x : row) {
            cin >> x;
        }
    }

    mat = calc_mat_power(mat, k);
    ll ans = 0;

    for (vector<ll> &row : mat) {
        for (ll &x : row) {
            ans += x;
        }

        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
