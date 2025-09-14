// Solve 2025-09-13

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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

pii find_start_node(vector<string>& board, int n, int m) {
    for (int y = 0; y < m; y++) {
        if (board[0][y] == 'S') {
            return {0, y};
        }
        else if (board[n - 1][y] == 'S') {
            return {n - 1, y};
        }
    }

    for (int x = 0; x < n; x++) {
        if (board[x][0] == 'S') {
            return {x, 0};
        }
        else if (board[x].back() == 'S') {
            return {x, m - 1};
        }
    }

    return {-1, -1};
}

int escape(vector<string>& board, int n, int m, pii start_node, int lr) {
    // lr이 -1이면 좌수법, 1이면 우수법

    int x = start_node.first;
    int y = start_node.second;
    int d = 0;
    int ret = 0;

    while (board[x][y] != 'E') {
        d = (d + lr + 4) % 4;
        int nx = x + dx[d];
        int ny = y + dy[d];

        while (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '*') {
            d = (d - lr + 4) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }

        x = nx;
        y = ny;
        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<string> board(n);

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    pii start_node = find_start_node(board, n, m);
    int cnt_left_escape = escape(board, n, m, start_node, -1);
    int cnt_right_escape = escape(board, n, m, start_node, 1);

    if (cnt_left_escape < cnt_right_escape) {
        cout << "LEFT IS BEST" << '\n';
    }
    else if (cnt_left_escape > cnt_right_escape) {
        cout << "RIGHT IS BEST" << '\n';
    }
    else {
        cout << "SAME" << '\n';
    }

    return 0;
}
