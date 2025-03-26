// Solve 2025-02-08 (대회 Solve)
// Update 2025-03-25

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pair{
    int x, y;

    Pair(int x, int y) : x(x), y(y) {
    }
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs1(vector<string> &storage, char target) {
    int res = 0;
    int n = storage.size();
    int m = storage[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<Pair> que;

    for (int x = 0; x < n; x++) {
        que.emplace(x, -1);
        que.emplace(x, m);
    }

    for (int y = 0; y < m; y++) {
        que.emplace(-1, y);
        que.emplace(n, y);
    }

    while (!que.empty()) {
        Pair p = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (storage[nx][ny] == '.') {
                que.emplace(nx, ny);
            }
            else if (storage[nx][ny] == target) {
                storage[nx][ny] = '.';
                res++;
            }
        }
    }

    return res;
}

int bfs2(vector<string> &storage, char target) {
    int res = 0;
    int n = storage.size();
    int m = storage[0].size();

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (storage[x][y] == target) {
                storage[x][y] = '.';
                res++;
            }
        }
    }

    return res;
}

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    int answer = n * m;

    for (string &req : requests) {
        char target = req[0];

        if (req.size() == 1) {
            answer -= bfs1(storage, target);
        }
        else {
            answer -= bfs2(storage, target);
        }
    }

    return answer;
}
