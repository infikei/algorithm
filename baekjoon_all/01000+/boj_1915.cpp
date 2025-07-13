// Solve 2023-07-26
// Update 2025-07-08

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

    int n, m;
    cin >> n >> m;

    int ans = 0;

    for (int x = 1; x <= n; x++) {
        string s;
        cin >> s;

        for (int y = 1; y <= m; y++) {
            if (s[y - 1] == '1') {
                memo[x][y] = min(memo[x][y - 1], min(memo[x - 1][y - 1], memo[x - 1][y])) + 1;
                ans = max(ans, memo[x][y]);
            }
        }
    }

    cout << ans * ans << '\n';
    return 0;
}
