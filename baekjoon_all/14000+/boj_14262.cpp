// Solve 2026-01-24

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

int n, m, t;
string board[50];
ll r, g, b;

void count_diagonal(int x, int y) {
    int last_pos = -1000;

    for (int i = 0; x < n && y < m; i++, x++, y++) {
        if (board[x][y] == '.') continue;

        int range_begin = max(last_pos, i);
        int range_end = i + t - 1;

        if (board[x][y] == 'R') {
            r += range_end - range_begin + 1;
        }
        else if (board[x][y] == 'G') {
            g += range_end - range_begin + 1;
        }
        else {
            b += range_end - range_begin + 1;
        }

        last_pos = range_end + 1;
    }
}

int main() {
    FASTIO;

    cin >> n >> m >> t;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int i = 1; i < m; i++) {
        count_diagonal(0, i);
    }

    for (int i = 0; i < n; i++) {
        count_diagonal(i, 0);
    }

    cout << r << '\n';
    cout << g << '\n';
    cout << b << '\n';

    return 0;
}
