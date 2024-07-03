// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {}
};

int dx[7] = { 0, 0, -1, -1, -1, 1, 1 };
int dy[7] = { -1, 1, -1, 0, 1, -1, 1 };
bool visited[2000][2000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    string board[2000];
    queue<Point> que;

    for (int row = 0; row < n; row++) {
        cin >> board[row];

        int pos = board[row].find('F');

        if (pos != string::npos) {
            que.push({ row, pos });
            visited[row][pos] = true;
        }
    }

    int cnt = 0;

    while (!que.empty()) {
        Point cur = que.front();
        que.pop();

        for (int i = 0; i < 7; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] || board[nx][ny] != '.') continue;

            visited[nx][ny] = true;
            que.push({ nx, ny });
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
