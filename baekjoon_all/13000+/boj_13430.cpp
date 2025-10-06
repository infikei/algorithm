// Solve 2023-03-12
// Update 2025-10-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using matrixll = vector<vector<ll>>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll mat_size;

matrixll mat_mul(const matrixll &a, const matrixll &b) {
    matrixll ret(mat_size, vector<ll>(mat_size, 0));

    for (int r = 0; r < mat_size; r++) {
        for (int c = 0; c < mat_size; c++) {
            for (int i = 0; i < mat_size; i++) {
                ret[r][c] += a[r][i] * b[i][c] % MOD;
            }

            ret[r][c] %= MOD;
        }
    }

    return ret;
}

matrixll mat_pow(matrixll a, ll b) {
    matrixll ret(mat_size, vector<ll>(mat_size, 0));

    for (int i = 0; i < mat_size; i++) {
        ret[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            ret = mat_mul(ret, a);
        }

        a = mat_mul(a, a);
        b >>= 1;
    }

    return ret;
}

int main() {
    FASTIO;

    ll k, n;
    cin >> k >> n;
    mat_size = k + 2;
    matrixll mat(mat_size, vector<ll>(mat_size, 0));

    for (int r = 0; r < mat_size; r++) {
        for (int c = 0; c <= r; c++) {
            mat[r][c] = 1;
        }
    }

    mat = mat_pow(mat, n);
    cout << mat[mat_size - 1][0] << '\n';
    return 0;
}
