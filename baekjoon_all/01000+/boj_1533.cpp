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
using matrixll = vector<vector<ll> >;

const ll MOD = 1000003;
int n, n5;

matrixll calc_mat_mul(const matrixll &a, const matrixll &b) {
    matrixll res(n5, vector<ll>(n5, 0));
    for (int row = 0; row < n5; row++) {
        for (int col = 0; col < n5; col++) {
            for (int idx = 0; idx < n5; idx++) {
                res[row][col] += a[row][idx] * b[idx][col];
            }
            res[row][col] %= MOD;
        }
    }
    return res;
}

matrixll calc_mat_power(matrixll a, ll b) {
    matrixll res(n5, vector<ll>(n5, 0));
    for (int i = 0; i < n5; i++) {
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

    int s, e;
    ll t;
    cin >> n >> s >> e >> t;

    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    n5 = n * 5;
    matrixll adj(n5, vector<ll>(n5, 0));
    for (int i5 = 0; i5 < n5; i5 += 5) {
        for (int j = 1; j < 5; j++) {
            adj[i5 + j][i5 + j - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dist = graph[i][j] - '0';
            if (dist > 0) {
                adj[i * 5][j * 5 + (dist - 1)] = 1;
            }
        }
    }

    matrixll ans = calc_mat_power(adj, t);
    cout << ans[(s - 1) * 5][(e - 1) * 5] << '\n';

    return 0;
}