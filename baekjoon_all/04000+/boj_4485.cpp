// Solve 2023-11-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

struct Node{
    int x, y, cost;

    Node(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool operator<(const Node &rhs) const {
        if (cost != rhs.cost) cost < rhs.cost;
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    bool operator>(const Node &rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    int ti = 0;

    while (true) {
        ti++;
        int n;
        cin >> n;

        if (n == 0) break;

        vector<vector<int> > board(n, vector<int>(n, 0));

        for (vector<int> &row : board) {
            for (int &x : row) {
                cin >> x;
            }
        }

        vector<vector<int> > costs(n, vector<int>(n, INF));
        priority_queue<Node, vector<Node>, greater<Node> > pq_mintop;
        costs[0][0] = board[0][0];
        pq_mintop.emplace(0, 0, board[0][0]);

        while (!pq_mintop.empty()) {
            Node now = pq_mintop.top();
            pq_mintop.pop();

            if (now.x == n - 1 && now.y == n - 1) break;
            if (costs[now.x][now.y] < now.cost) continue;

            for (int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int ncost = now.cost + board[nx][ny];

                if (costs[nx][ny] > ncost) {
                    costs[nx][ny] = ncost;
                    pq_mintop.emplace(nx, ny, ncost);
                }
            }
        }

        cout << "Problem " << ti << ": " << costs[n - 1][n - 1] << '\n';
    }

    return 0;
}
