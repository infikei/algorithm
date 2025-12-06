// Solve 2025-12-05

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

int board[752][752];
int lu[752][752];
int ru[752][752];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            char c;
            cin >> c;
            board[x][y] = c - '0';
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (board[x][y]) {
                lu[x][y] = lu[x - 1][y - 1] + 1;
                ru[x][y] = ru[x - 1][y + 1] + 1;
            }
        }
    }

    int mx = 0;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (board[x][y] == 0) continue;

            int k = min(lu[x][y], ru[x][y]);

            for (int i = k; i > mx; i--) {
                if (ru[x - i + 1][y - i + 1] >= i && lu[x - i + 1][y + i - 1] >= i) {
                    mx = max(mx, i);
                }
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
