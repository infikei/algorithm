// Solve 2023-04-11
// Update 2025-09-13

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

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[100][100];

int count_area(vector<string>& board, int n, map<char, char>& color_map) {
    memset(visited, false, sizeof visited);
    queue<Point> bfs_que;
    int area_cnt = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[x][y]) continue;

            area_cnt++;
            char color = color_map[board[x][y]];
            visited[x][y] = true;
            bfs_que.emplace(x, y);

            while (!bfs_que.empty()) {
                Point cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || color_map[board[nx][ny]] != color) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }
            }
        }
    }

    return area_cnt;
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<string> board(n);

    for (string& row : board) {
        cin >> row;
    }

    map<char, char> color_map;
    color_map['R'] = 'R';
    color_map['G'] = 'G';
    color_map['B'] = 'B';
    int area_cnt = count_area(board, n, color_map);

    color_map['G'] = 'R';
    int area_cnt2 = count_area(board, n, color_map);

    cout << area_cnt << ' ' << area_cnt2 << '\n';
    return 0;
}
