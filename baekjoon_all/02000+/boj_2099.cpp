// Solve 2023-03-08

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
using matrix = vector<vector<bool> >;

int n;

matrix calc_mat_mul(const matrix &a, const matrix &b) {
    matrix res(n, vector<bool>(n, false));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int idx = 0; idx < n; idx++) {
                if (a[row][idx] && b[idx][col]) {
                    res[row][col] = true;
                    break;
                }
            }
        }
    }
    return res;
}

matrix calc_mat_power(matrix a, int b) {
    matrix res(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        res[i][i] = true;
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

    int k, m;
    cin >> n >> k >> m;
    matrix adj(n, vector<bool>(n, false));
    for (int row = 0; row < n; row++) {
        int a, b;
        cin >> a >> b;
        adj[row][a - 1] = adj[row][b - 1] = true;
    }

    adj = calc_mat_power(adj, k);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (adj[a - 1][b - 1]) {
            cout << "death\n";
        }
        else {
            cout << "life\n";
        }
    }

    return 0;
}