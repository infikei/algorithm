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

string board[1000];
int board2[1000][1000];
vector<int> areas = { 0 };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            // 벽이 있거나, 이미 탐색한 칸이라면 continue
            if (board[x][y] != '0' || board2[x][y] != 0) continue;

            int area_num = areas.size();
            int area_cnt = 1;
            queue<pii> bfs_que;
            bfs_que.emplace(x, y);
            board2[x][y] = area_num;

            while (!bfs_que.empty()) {
                pii cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    // 벽이 있거나, 이미 탐색한 칸이라면 continue
                    if (board[nx][ny] != '0' || board2[nx][ny] != 0) continue;

                    board2[nx][ny] = area_num;
                    bfs_que.emplace(nx, ny);
                    area_cnt++;
                }
            }

            areas.push_back(area_cnt);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board2[x][y] != 0) continue;

            set<int> st;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board2[nx][ny] == 0) continue;

                st.insert(board2[nx][ny]);
            }

            int cnt = 1;

            for (auto it = st.begin(); it != st.end(); it++) {
                cnt += areas[*it];
            }

            board[x][y] = '0' + (cnt % 10);
        }
    }

    for (int x = 0; x < n; x++) {
        cout << board[x] << '\n';
    }

    return 0;
}
