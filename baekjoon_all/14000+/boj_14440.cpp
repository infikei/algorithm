// Solve 2026-01-15

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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<vector<int>> mat_mod_mul(vector<vector<int>>& a, vector<vector<int>>& b, int mod) {
    vector<vector<int>> ret(size(a), vector<int>(size(b[0]), 0));

    for (int i = 0; i < size(a); i++) {
        for (int j = 0; j < size(b[0]); j++) {
            for (int k = 0; k < size(b); k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }

            ret[i][j] %= mod;
        }
    }

    return ret;
}

vector<vector<int>> mat_mod_pow(vector<vector<int>>& a, int b, int mod) {
    vector<vector<int>> ret(size(a), vector<int>(size(a), 0));

    for (int i = 0; i < size(a); i++) {
        ret[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            ret = mat_mod_mul(ret, a, mod);
        }

        a = mat_mod_mul(a, a, mod);
        b >>= 1;
    }

    return ret;
}

int main() {
    FASTIO;

    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n;

    if (n == 0) {
        SETW(2, '0');
        cout << a0 << '\n';
        return 0;
    }

    if (n == 1) {
        SETW(2, '0');
        cout << a1 << '\n';
        return 0;
    }

    vector<vector<int>> mat = {
        {x, y},
        {1, 0}
    };

    mat = mat_mod_pow(mat, n - 1, 100);
    int ans = (mat[0][0] * a1 + mat[0][1] * a0) % 100;
    SETW(2, '0');
    cout << ans << '\n';
    return 0;
}
