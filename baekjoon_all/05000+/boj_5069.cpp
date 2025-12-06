// Solve 2025-12-04

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

int memo[15][32][32];
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};

void pre() {
    memo[0][15][15] = 1;

    for (int i = 1; i <= 14; i++) {
        for (int x = 1; x <= 29; x++) {
            for (int y = 1; y <= 29; y++) {
                for (int d = 0; d < 6; d++) {
                    memo[i][x][y] += memo[i - 1][x + dx[d]][y + dy[d]];
                }
            }
        }
    }
}

int main() {
    FASTIO;
    pre();

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        cout << memo[n][15][15] << '\n';
    }

    return 0;
}
