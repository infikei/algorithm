// Solve 2025-06-14
// Update 2025-06-16

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

int n, k;
string board[50];
int memo[50][50][2][4];

int recur(int x, int y, int dir, int turned_cnt) {
    if (turned_cnt > k) return 0;
    if (x >= n || y >= n) return 0;
    if (board[x][y] != '.') return 0;
    if (x == n - 1 && y == n - 1) return 1;

    if (x == 0 && y == 0) {
        return recur(0, 1, 0, 0) + recur(1, 0, 1, 0);
    }

    int& ret = memo[x][y][dir][turned_cnt];

    if (~ret) return ret;

    ret = 0;

    if (dir == 0) {
        ret += recur(x, y + 1, 0, turned_cnt);
        ret += recur(x + 1, y, 1, turned_cnt + 1);
    }
    else if (dir == 1) {
        ret += recur(x, y + 1, 0, turned_cnt + 1);
        ret += recur(x + 1, y, 1, turned_cnt);
    }

    return ret;
}

void input() {
    cin >> n >> k;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }
}

void pro() {
    memset(memo, -1, sizeof memo);
    cout << recur(0, 0, 2, 0) << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        input();
        pro();
    }

    return 0;
}
