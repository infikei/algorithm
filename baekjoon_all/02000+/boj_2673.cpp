// Solve 2025-11-27

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

int chord[101][101];
int memo[101][101];

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int u, v;
        cin >> u >> v;

        if (u > v) swap(u, v);

        chord[u][v] = 1;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = i - 1; j >= 1; j--) {
            memo[j][i] = chord[j][i];

            for (int k = j; k < i; k++) {
                memo[j][i] = max(memo[j][i], memo[j][k] + memo[k + 1][i] + chord[j][i]);
            }
        }
    }

    cout << memo[1][100] << '\n';
    return 0;
}
