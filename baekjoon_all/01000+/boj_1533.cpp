// Solve 2023-03-08
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using matrixll = vector<vector<ll>>;

const ll MOD = 1000003;

matrixll get_matmul_with_mod(int mat_size, const matrixll &a, const matrixll &b) {
    matrixll res(mat_size, vector<ll>(mat_size, 0));

    for (int row = 0; row < mat_size; row++) {
        for (int col = 0; col < mat_size; col++) {
            for (int idx = 0; idx < mat_size; idx++) {
                res[row][col] += a[row][idx] * b[idx][col];
            }

            res[row][col] %= MOD;
        }
    }

    return res;
}

matrixll get_matpow_with_mod(int mat_size, matrixll a, ll b) {
    matrixll res(mat_size, vector<ll>(mat_size, 0));

    for (int i = 0; i < mat_size; i++) {
        res[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            res = get_matmul_with_mod(mat_size, res, a);
        }

        a = get_matmul_with_mod(mat_size, a, a);
        b >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    int n, s, e;
    ll t;
    cin >> n >> s >> e >> t;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    int n5 = n * 5;
    matrixll adj(n5, vector<ll>(n5, 0));

    for (int i5 = 0; i5 < n5; i5 += 5) {
        for (int j = 1; j < 5; j++) {
            adj[i5 + j][i5 + j - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dist = board[i][j] - '0';

            if (dist > 0) {
                adj[i * 5][j * 5 + (dist - 1)] = 1;
            }
        }
    }

    matrixll adj_after_pow = get_matpow_with_mod(n5, adj, t);
    int ans = adj_after_pow[(s - 1) * 5][(e - 1) * 5];
    cout << ans << '\n';

    return 0;
}
