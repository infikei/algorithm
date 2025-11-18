// Solve 2025-11-17

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

int board[20][20];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int mn = INF;

    for (int b = 0; b < (1 << n); b += 2) {
        int score = 0;

        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) continue;

            for (int j = i + 1; j < n; j++) {
                if (b & (1 << j)) continue;

                score += board[i][j] + board[j][i];
            }
        }

        for (int i = 0; i < n; i++) {
            if ((b & (1 << i)) == 0) continue;

            for (int j = i + 1; j < n; j++) {
                if ((b & (1 << j)) == 0) continue;

                score -= board[i][j] + board[j][i];
            }
        }

        mn = min(mn, abs(score));
    }

    cout << mn << '\n';
    return 0;
}
