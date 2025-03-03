// Solve 2023-09-14
// Update 2025-03-03

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(string &board) {
    string target_board = "123456780";

    if (board == target_board) {
        return 0;
    }

    unordered_set<string> hs;
    hs.insert(board);

    queue<string> que;
    que.push(board);

    int cnt = 0;

    while (!que.empty()) {
        cnt++;
        int iter = SIZE(que);

        while (iter-- > 0) {
            string cur_board = que.front();
            que.pop();

            int z = 0;

            for (int i = 0; i < 9; i++) {
                if (cur_board[i] == '0') {
                    z = i;
                }
            }

            int x = z / 3;
            int y = z % 3;

            for (int d = 0; d < 4; d++) {
                string nxt_board = cur_board;
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

                int nz = nx * 3 + ny;
                swap(nxt_board[z], nxt_board[nz]);

                if (nxt_board == target_board) {
                    return cnt;
                }

                if (hs.find(nxt_board) == hs.end()) {
                    hs.insert(nxt_board);
                    que.push(nxt_board);
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    string board(9, '0');

    for (char &c : board) {
        cin >> c;
    }

    int ans = dfs(board);

    cout << ans << '\n';

    return 0;
}
