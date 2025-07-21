// Solve 2025-07-21

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
    int z, x, y;

    Point(int z, int x, int y) : z(z), x(x), y(y) {
    }
};

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int layers[5][4][5][5];
int maze[5][5][5];
bool visited[5][5][5];
int ans = INF;

int bfs() {
    if (maze[0][0][0] == 0) return INF;
    if (maze[4][4][4] == 0) return INF;

    memset(visited, 0, sizeof visited);
    queue<Point> bfs_que;
    bfs_que.emplace(0, 0, 0);
    visited[0][0][0] = true;
    int ret = 0;

    while (!bfs_que.empty()) {
        ret++;
        int iter = size(bfs_que);

        while (iter-- > 0) {
            Point cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 6; d++) {
                int nz = cur.z + dz[d];
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (maze[nz][nx][ny] == 0) continue;
                if (visited[nz][nx][ny]) continue;
                if (nz == 4 && nx == 4 && ny == 4) return ret;

                visited[nz][nx][ny] = true;
                bfs_que.emplace(nz, nx, ny);
            }
        }
    }

    return INF;
}

void copy_layer(int depth, int z, int d) {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            maze[depth][x][y] = layers[z][d][x][y];
        }
    }
}

void recur2(int depth, vector<int>& layer_nums) {
    if (depth == 5) {
        ans = min(ans, bfs());
        return;
    }

    for (int d = 0; d < 4; d++) {
        copy_layer(depth, layer_nums[depth], d);
        recur2(depth + 1, layer_nums);
    }
}

void recur(int depth, vector<int>& layer_nums, vector<bool>& layer_visited) {
    if (depth == 5) {
        recur2(0, layer_nums);
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (layer_visited[i]) continue;

        layer_visited[i] = true;
        layer_nums[depth] = i;
        recur(depth + 1, layer_nums, layer_visited);
        layer_visited[i] = false;
    }
}

void rotate_layer(int z, int d) {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            layers[z][d][y][4 - x] = layers[z][d - 1][x][y];
        }
    }
}

int main() {
    FASTIO;

    for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                cin >> layers[z][0][x][y];
            }
        }
    }

    for (int z = 0; z < 5; z++) {
        for (int d = 1; d < 4; d++) {
            rotate_layer(z, d);
        }
    }

    vector<int> layer_nums(5);
    vector<bool> layer_visited(5);
    recur(0, layer_nums, layer_visited);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
