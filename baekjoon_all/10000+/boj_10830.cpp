// Solve 2022-12-06
// Update 2025-09-16

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
using matrix = vector<vector<int>>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000;

matrix mat_mul(const matrix& a, const matrix& b) {
    int n1 = size(a);
    int n2 = size(b);
    int n3 = size(b[0]);
    matrix ret(n3, vector<int>(n1, 0));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            for (int k = 0; k < n2; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }

            ret[i][j] %= MOD;
        }
    }

    return ret;
}

matrix mat_pow(matrix a, ll b) {
    int n = size(a);
    matrix ret(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
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

    int n;
    ll b;
    cin >> n >> b;
    matrix a(n, vector<int>(n, 0));

    for (vector<int>& row : a) {
        for (int& x : row) {
            cin >> x;
        }
    }

    matrix ans = mat_pow(a, b);

    for (vector<int>& row : ans) {
        for (int& x : row) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
