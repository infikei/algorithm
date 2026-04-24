// Solve 2026-04-11

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

int memo[201][201][201];

int main() {
    FASTIO;

    memset(memo, 0x3f, sizeof(memo));

    for (int i = 1; i <= 200; i++) {
        memo[i][i][i] = 1;
    }

    for (int i = 1; i <= 200; i++) {
        for (int j = i; j <= 200; j++) {
            for (int k = j; k <= 200; k++) {
                for (int h = i / 2; h >= 1; h--) {
                    memo[i][j][k] = min(memo[i][j][k], memo[h][j][k] + memo[i - h][j][k]);
                }

                for (int h = j / 2; h >= 1; h--) {
                    memo[i][j][k] = min(memo[i][j][k], memo[i][h][k] + memo[i][j - h][k]);
                }

                for (int h = k / 2; h >= 1; h--) {
                    memo[i][j][k] = min(memo[i][j][k], memo[i][j][h] + memo[i][j][k - h]);
                }

                memo[i][k][j] = memo[i][j][k];
                memo[j][i][k] = memo[i][j][k];
                memo[j][k][i] = memo[i][j][k];
                memo[k][i][j] = memo[i][j][k];
                memo[k][j][i] = memo[i][j][k];
            }
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int w, l, h;
        cin >> w >> l >> h;
        cout << memo[w][l][h] << '\n';
    }

    return 0;
}
