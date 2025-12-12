// Solve 2025-12-10

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
string board[30];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check(int x, int y, int d) {
    int nx1 = x + dx[d];
    int ny1 = y + dy[d];
    int nx2 = x + dx[d + 4];
    int ny2 = y + dy[d + 4];

    if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n) return false;
    if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n) return false;
    if (board[nx1][ny1] != board[x][y]) return false;
    if (board[nx2][ny2] != board[x][y]) return false;

    return true;
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == '.') continue;

            for (int d = 0; d < 4; d++) {
                if (check(x, y, d)) {
                    cout << board[x][y] << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "ongoing" << '\n';
    return 0;
}
