// Solve 2026-04-06

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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n_blocks;

bool is_connected(int board) {
    int ix = 0;
    int iy = 0;

    for (int w = 0; w < 25; w++) {
        if (board & (1 << w)) {
            ix = w / 5;
            iy = w % 5;
            break;
        }
    }

    int visited = 0;
    queue<pii> que;
    visited |= (1 << (ix * 5 + iy));
    que.emplace(ix, iy);
    int connected_blocks = 1;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nw = nx * 5 + ny;

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited & (1 << nw)) continue;
            if ((board & (1 << nw)) == 0) continue;

            visited |= (1 << nw);
            que.emplace(nx, ny);
            connected_blocks++;
        }
    }

    return connected_blocks == n_blocks;
}

void get_next_boards(int cur_board, vector<int>& nxt_boards) {
    for (int w = 0; w < 25; w++) {
        if (cur_board & (1 << w)) {
            int x = w / 5;
            int y = w % 5;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int nw = nx * 5 + ny;

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if ((cur_board & (1 << nw)) != 0) continue;

                int nxt_board = cur_board ^ ((1 << w) | (1 << nw));
                nxt_boards.push_back(nxt_board);
            }
        }
    }
}

int main() {
    FASTIO;

    int board = 0;

    for (int x = 0; x < 5; x++) {
        string s;
        cin >> s;

        for (int y = 0; y < 5; y++) {
            if (s[y] == '*') {
                board |= (1 << (x * 5 + y));
            }
        }
    }

    n_blocks = __builtin_popcount(board);

    if (is_connected(board)) {
        cout << 0 << '\n';
        return 0;
    }

    set<int> visited;
    queue<int> que;
    visited.insert(board);
    que.push(board);
    int level = 0;

    while (!que.empty()) {
        level++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur_board = que.front();
            que.pop();

            vector<int> nxt_boards;
            get_next_boards(cur_board, nxt_boards);

            for (int nxt_board : nxt_boards) {
                if (is_connected(nxt_board)) {
                    cout << level << '\n';
                    return 0;
                }

                if (visited.find(nxt_board) != visited.end()) continue;

                visited.insert(nxt_board);
                que.push(nxt_board);
            }
        }
    }

    return 0;
}
