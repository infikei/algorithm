// Solve 2022-12-06
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

const ll MOD = 1000;
int n;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(n, vector<ll>(n, 0));
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

matrixll calc_mat_power(matrixll a, ll b) {
    matrixll res(n, vector<ll>(n, 0));
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

    ll b;
    cin >> n >> b;

    matrixll a(n, vector<ll>(n, 0));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> a[row][col];
        }
    }

    matrixll ans = calc_mat_power(a, b);
    for (auto row : ans) {
        for (auto i : row) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}