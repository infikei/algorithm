// Solve 2025-12-21

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

string board[100];
string tmp[100];
int prefix[101][101];

int main() {
    FASTIO;

    int n, m, t, k, a, b;
    cin >> n >> m >> t >> k >> a >> b;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
        tmp[x] = board[x];
    }

    while (t-- > 0) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                prefix[x][y] = prefix[x][y - 1] + prefix[x - 1][y] - prefix[x - 1][y - 1];

                if (board[x - 1][y - 1] == '*') {
                    prefix[x][y]++;
                }
            }
        }

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                int x0 = max(0, x - k - 1);
                int x1 = min(n, x + k);
                int y0 = max(0, y - k - 1);
                int y1 = min(m, y + k);

                int v = prefix[x1][y1] - prefix[x1][y0] - prefix[x0][y1] + prefix[x0][y0];

                if (board[x - 1][y - 1] == '*') {
                    v--;
                    tmp[x - 1][y - 1] = (a <= v && v <= b) ? '*' : '.';
                }
                else {
                    tmp[x - 1][y - 1] = (a < v && v <= b) ? '*' : '.';
                }
            }
        }

        swap(board, tmp);
    }

    for (int x = 0; x < n; x++) {
        cout << board[x] << '\n';
    }

    return 0;
}
