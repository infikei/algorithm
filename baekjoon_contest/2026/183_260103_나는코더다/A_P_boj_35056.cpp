// Solve 2026-01-03

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

int n;
ll a[2001];
ll b[2001];
ll memo[2001][2001];

int main() {
    FASTIO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        cin >> b[i];
    }

    for (int j = 1; j <= n; j++) {
        memo[1][j] = max(memo[1][j - 1], a[j]);
    }

    cout << memo[1][n] << '\n';

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            memo[i][j] = max(memo[i - 1][j - 1] + a[j], memo[i - 2][j - 2] + a[j - 1] + a[j] + b[j - 1]);
            memo[i][j] = max(memo[i][j], memo[i][j - 1]);
        }

        cout << memo[i][n] << '\n';
    }

    return 0;
}
