// Solve 2025-10-06

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

int n, m;
int board[100][100];

int apply_gravity(int x, int y) {
    if (board[x][y] == 0) return 0;

    int ret = 0;

    while (x + 1 < n && board[x + 1][y] == 0) {
        board[x + 1][y] = 1;
        board[x][y] = 0;
        x++;
        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n >> m; // 세로 길이를 n, 가로 길이를 m으로 재정의

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> board[x][y];
            }
        }

        int cnt = 0;

        for (int y = 0; y < m; y++) {
            for (int x = n - 1; x >= 0; x--) {
                cnt += apply_gravity(x, y);
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
