// Solve 2023-11-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Node{
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    int n;
    cin >> n;

    vector<string> board(n, "");

    for (string &row : board) {
        cin >> row;
    }

    vector<vector<int> > dists(n, vector<int>(n, -1));
    deque<Node> dque;
    dists[0][0] = 0;
    dque.emplace_back(0, 0);

    while (!dque.empty()) {
        Node now = dque.front();
        dque.pop_front();

        if (now.x == n - 1 && now.y == n - 1) break;

        for (int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dists[nx][ny] != -1) continue;

            if (board[nx][ny] == '1') {
                dists[nx][ny] = dists[now.x][now.y];
                dque.emplace_front(nx, ny);
            }
            else {
                dists[nx][ny] = dists[now.x][now.y] + 1;
                dque.emplace_back(nx, ny);
            }
        }
    }

    cout << dists[n - 1][n - 1] << '\n';

    return 0;
}
