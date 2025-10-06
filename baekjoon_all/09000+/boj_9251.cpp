// Solve 2022-08-03
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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int memo[1001][1001];

int main() {
    FASTIO;

    string s, t;
    cin >> s >> t;
    int n = size(s);
    int m = size(t);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }

    cout << memo[n][m] << '\n';
    return 0;
}
