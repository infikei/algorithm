// Solve 2023-03-12
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
                res[row][col] += a[row][idx] * b[idx][col];
            }

            res[row][col] %= MOD;
        }
    }

    return res;
}

matrix calc_mat_power(matrix a, int b) {
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

    int t;
    cin >> t;

    matrix mat = {
        { 6, -4 },
        { 1, 0 }
    };

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        matrix ans_mat = calc_mat_power(mat, n - 1);
        int ans = (ans_mat[0][0] * 6 + ans_mat[0][1] * 2 - 1) % MOD;

        if (ans < 0) ans += MOD;

        cout << "Case #" << ti << ": " << setfill('0') << setw(3) << ans << '\n';
    }

    return 0;
}
