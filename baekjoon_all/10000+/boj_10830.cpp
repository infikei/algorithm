// Solve 2022-12-06
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using matrix = vector<vector<int>>;

const int MOD = 1000;

matrix calc_mat_mul(const matrix &a, const matrix &b) {
    int n = SIZE(a);
    matrix res(n, vector<int>(n, 0));

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int idx = 0; idx < n; idx++) {
                res[row][col] += a[row][idx] * b[idx][col] % MOD;
            }

            res[row][col] %= MOD;
        }
    }

    return res;
}

matrix calc_mat_power(matrix a, ll b) {
    int n = SIZE(a);
    matrix res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
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

    int n;
    ll b;
    cin >> n >> b;

    matrix a(n, vector<int>(n, 0));

    for (vector<int> &row : a) {
        for (int &x : row) {
            cin >> x;
        }
    }

    matrix ans = calc_mat_power(a, b);

    for (vector<int> &row : ans) {
        for (int &x : row) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
