#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int m, n, k, answer_cnt;
bool board[100][100];
vector<int> answers;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(int y0, int x0) {
    int res = 0;
    queue<pii> q;
    board[y0][x0] = true;
    res++;
    q.push(make_pair(y0, x0));

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || board[ny][nx]) continue;
            board[ny][nx] = true;
            res++;
            q.push(make_pair(ny, nx));
        }
    }
    answer_cnt++;
    answers.push_back(res);
}

int main() {
    fastio;

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                board[y][x] = true;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x]) continue;
            bfs(y, x);
        }
    }

    cout << answer_cnt << '\n';
    sort(answers.begin(), answers.end());
    for (auto ans : answers) cout << ans << ' ';
    cout << '\n';

    return 0;
}