// Solve 2026-04-13

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

int prod[1001];
int memo[2][1001];

int main() {
    FASTIO;

    int n, a0, b0, k;
    cin >> n >> a0 >> b0 >> k;

    int s0 = a0 + b0;

    for (int i = 0; i <= s0; i++) {
        prod[i] = i * (s0 - i);
        memo[0][i] = -INF;
    }

    memo[0][a0] = 0;

    for (int day = 1; day <= n; day++) {
        for (int i = 0; i <= s0; i++) {
            memo[1][i] = -INF;

            for (int j = 0; j <= i - k; j++) {
                memo[1][i] = max(memo[1][i], memo[0][j] + prod[i]);
            }

            for (int j = i + k; j <= s0; j++) {
                memo[1][i] = max(memo[1][i], memo[0][j] + prod[i]);
            }
        }

        swap(memo[0], memo[1]);
    }

    int mx = 0;

    for (int i = 0; i <= s0; i++) {
        mx = max(mx, memo[0][i]);
    }

    cout << mx << '\n';
    return 0;
}
