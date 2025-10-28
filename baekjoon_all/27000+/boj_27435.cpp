// Solve 2025-10-28

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
using matll = vector<vector<ll>>;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

matll mat_mod_mul(const matll& a, const matll& b) {
    int n = size(a);
    int m = size(b);
    int k = size(b[0]);
    matll ret(n, vector<ll>(k));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < k; y++) {
            for (int z = 0; z < m; z++) {
                ret[x][y] += a[x][z] * b[z][y] % MOD;
            }

            ret[x][y] %= MOD;
        }
    }

    return ret;
}

matll mat_mod_pow(matll a, ll p) {
    int n = size(a);
    matll ret(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        ret[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) {
            ret = mat_mod_mul(ret, a);
        }

        a = mat_mod_mul(a, a);
        p >>= 1;
    }

    return ret;
}

ll get_padovan(ll n) {
    if (n <= 3) return 1;

    matll mat = {
        {0, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    mat = mat_mod_pow(mat, n - 3);

    matll mat2 = {
        {1},
        {1},
        {1}
    };

    mat = mat_mod_mul(mat, mat2);
    return mat[0][0];
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;
        cout << get_padovan(n) << '\n';
    }

    return 0;
}
