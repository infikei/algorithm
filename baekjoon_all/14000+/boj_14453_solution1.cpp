// Solve 2025-02-21
// Update 2025-12-08

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

int memo[100001][3];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int d = (c == 'H' ? 0 : c == 'P' ? 1 : 2);

        memo[i][0] = memo[i - 1][0];
        memo[i][1] = memo[i - 1][1];
        memo[i][2] = memo[i - 1][2];
        memo[i][d]++;
    }

    int mx = 0;

    for (int i = 1; i <= n; i++) {
        int x1 = *max_element(memo[i], memo[i] + 3);
        int x2 = max({memo[n][0] - memo[i][0], memo[n][1] - memo[i][1], memo[n][2] - memo[i][2]});
        mx = max(mx, x1 + x2);
    }

    cout << mx << '\n';
    return 0;
}
