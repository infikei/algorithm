// Solve 2025-09-16

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

int board[101][101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int min_dist = INF;
    pii min_pos;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            int seat_state;
            cin >> seat_state;

            if (seat_state == 0) {
                int dist = x + abs((m + 1) / 2 - y);

                if (dist < min_dist) {
                    min_dist = dist;
                    min_pos = {x, y};
                }
            }
        }
    }

    if (min_dist == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << min_pos.first << ' ' << min_pos.second << '\n';
    }

    return 0;
}
