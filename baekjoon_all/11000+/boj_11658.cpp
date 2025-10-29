// Solve 2025-10-29

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
int board[1025][1025];
ll fenwick[1025][1025];

void update_fenwick(int x, int y, ll diff) {
    for (int i = x; i <= n; i += (i & -i)) {
        for (int j = y; j <= n; j += (j & -j)) {
            fenwick[i][j] += diff;
        }
    }
}

ll get_from_fenwick(int x, int y) {
    ll ret = 0;

    for (int i = x; i >= 1; i -= (i & -i)) {
        for (int j = y; j >= 1; j -= (j & -j)) {
            ret += fenwick[i][j];
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int q;
    cin >> n >> q;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cin >> board[x][y];
            update_fenwick(x, y, board[x][y]);
        }
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            int diff = c - board[x][y];
            board[x][y] = c;
            update_fenwick(x, y, diff);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll ans = get_from_fenwick(x2, y2) - get_from_fenwick(x2, y1 - 1) - get_from_fenwick(x1 - 1, y2) + get_from_fenwick(x1 - 1, y1 - 1);
            cout << ans << '\n';
        }
    }

    return 0;
}
