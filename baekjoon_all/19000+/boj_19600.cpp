// Solve 2025-12-08

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

int memo[5001][5001];

void binary_search(int v, int l, int r, int n) {
    if (l > r) return;

    int mid = (l + r) / 2;
    memo[n][mid] -= v;
    binary_search(v + 1, l, mid - 1, n);
    binary_search(v + 1, mid + 1, r, n);
}

void ternary_search(int v, int l, int r, int n) {
    if (l > r) return;

    int l_third = l + (r - l) / 3;
    int r_third = r - (r - l) / 3;
    memo[n][l_third] += v;
    if (l_third != r_third) memo[n][r_third] += v + 1;
    ternary_search(v + 2, l, l_third - 1, n);
    ternary_search(v + 2, l_third + 1, r_third - 1, n);
    ternary_search(v + 2, r_third + 1, r, n);
}

int main() {
    FASTIO;

    for (int n = 1; n <= 5000; n++) {
        binary_search(0, 1, n, n);
        ternary_search(0, 1, n, n);

        for (int i = 1; i <= n; i++) {
            memo[n][i] += memo[n][i - 1];
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int n, s, e;
        cin >> n >> s >> e;
        cout << memo[n][e + 1] - memo[n][s] << '\n';
    }

    return 0;
}
