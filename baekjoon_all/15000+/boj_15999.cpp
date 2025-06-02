// Solve 2025-05-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string board[2000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

ll get_pow(ll a, ll b, ll mod) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            bool flag = true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (board[x][y] != board[nx][ny]) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }
    }

    ll ans = get_pow(2, cnt, 1000000007);
    cout << ans << '\n';

    return 0;
}
