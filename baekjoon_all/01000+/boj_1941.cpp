// Solve 2025-09-05

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

vector<string> board;
int selected_num[7];
bool board_selected[5][5];
bool visited[5][5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = 0;

bool is_ds_more_than_four() {
    int cnt = 0;

    for (int i = 0; i < 7; i++) {
        int x = selected_num[i] / 5;
        int y = selected_num[i] % 5;

        if (board[x][y] == 'S') {
            cnt++;
        }
    }

    return cnt >= 4;
}

bool is_adjacent_component() {
    int x0 = selected_num[0] / 5;
    int y0 = selected_num[0] % 5;
    memset(visited, false, sizeof visited);
    queue<pii> bfs_que;
    visited[x0][y0] = true;
    bfs_que.emplace(x0, y0);
    int cnt = 1;

    while (!bfs_que.empty()) {
        int x = bfs_que.front().first;
        int y = bfs_que.front().second;
        bfs_que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (!board_selected[nx][ny] || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            bfs_que.emplace(nx, ny);
            cnt++;
        }
    }

    return cnt == 7;
}

bool validate() {
    if (!is_ds_more_than_four()) return false;

    memset(board_selected, false, sizeof board_selected);

    for (int i = 0; i < 7; i++) {
        int x = selected_num[i] / 5;
        int y = selected_num[i] % 5;
        board_selected[x][y] = true;
    }

    return is_adjacent_component();
}

void dfs(int depth, int cur) {
    if (depth == 7) {
        if (validate()) ans++;
        return;
    }

    for (int nxt = cur; nxt < 25; nxt++) {
        selected_num[depth] = nxt;
        dfs(depth + 1, nxt + 1);
    }
}

int main() {
    FASTIO;

    for (int x = 0; x < 5; x++) {
        string row;
        cin >> row;
        board.push_back(row);
    }

    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}
