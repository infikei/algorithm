// Solve 2025-12-29

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

bool board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    FASTIO;

    vector<vector<int>> dragon(11);

    for (int g = 1; g <= 10; g++) {
        dragon[g] = dragon[g - 1];
        dragon[g].push_back(1);

        for (int i = (int) size(dragon[g - 1]) - 1; i >= 0; i--) {
            dragon[g].push_back(-dragon[g - 1][i]);
        }
    }

    int n;
    cin >> n;

    while (n-- > 0) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        board[x][y] = true;
        x += dx[d];
        y += dy[d];
        board[x][y] = true;

        for (int dd : dragon[g]) {
            d = (d + dd + 4) % 4;
            x += dx[d];
            y += dy[d];
            board[x][y] = true;
        }
    }

    int cnt = 0;

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (board[x][y] && board[x][y + 1] && board[x + 1][y] && board[x + 1][y + 1]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
