// Solve 2025-06-30

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
int board[5][5];
bool visited[5][5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int recur(int depth, int score) {
    if (depth == n * m) {
        return score;
    }

    int res = 0;
    int x = depth / m;
    int y = depth % m;

    for (int d = 0; d < 4; d++) {
        if (visited[x][y]) continue;

        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!is_in_range(nx, ny) || visited[nx][ny]) continue;

        int d2 = (d + 1) % 4;
        int nx2 = x + dx[d2];
        int ny2 = y + dy[d2];
        if (!is_in_range(nx2, ny2) || visited[nx2][ny2]) continue;

        visited[x][y] = true;
        visited[nx][ny] = true;
        visited[nx2][ny2] = true;

        int nxt_res = recur(depth + 1, score + board[x][y] * 2 + board[nx][ny] + board[nx2][ny2]);
        res = max(res, nxt_res);

        visited[x][y] = false;
        visited[nx][ny] = false;
        visited[nx2][ny2] = false;
    }

    int nxt_res = recur(depth + 1, score);
    res = max(res, nxt_res);
    return res;
}

void input() {
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }
}

void pro() {
    cout << recur(0, 0) << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
