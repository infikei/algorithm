// Solve 2025-11-19

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

string board[1000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < m; y++) {
            if (board[x - 1][y - 1] == '1' && board[x - 1][y] == '1' && board[x][y - 1] == '1' && board[x][y] == '1') {
                cout << 1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';
    return 0;
}
