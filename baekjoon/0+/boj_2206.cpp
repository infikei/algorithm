#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int N, M, ans;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string board[1000];
bool visited[1000][1000][2];
queue<pii> bfs_queue[2];

void bfs() {
    ans++;
    if (N == 1 && M == 1) {
        return;
    }
    visited[0][0][0] = true;
    bfs_queue[0].push(make_pair(0, 0));

    while (true) {
        ans++;

        int i_end0 = bfs_queue[0].size();
        int i_end1 = bfs_queue[1].size();

        for (int i = 0; i < i_end0; i++) {
            pii now = bfs_queue[0].front();
            bfs_queue[0].pop();

            for (int j = 0; j < 4; j++) {
                int next_x = now.first + dx[j];
                int next_y = now.second + dy[j];
                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
                    continue;
                }
                if (visited[next_x][next_y][0]) {
                    continue;
                }
                if (next_x == N - 1 && next_y == M - 1) {
                    return;
                }
                visited[next_x][next_y][0] = true;
                if (board[next_x][next_y] == '0') {
                    bfs_queue[0].push(make_pair(next_x, next_y));
                }
                else {
                    bfs_queue[1].push(make_pair(next_x, next_y));
                }
            }
        }

        for (int i = 0; i < i_end1; i++) {
            pii now = bfs_queue[1].front();
            bfs_queue[1].pop();

            for (int j = 0; j < 4; j++) {
                int next_x = now.first + dx[j];
                int next_y = now.second + dy[j];
                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
                    continue;
                }
                if (board[next_x][next_y] == '1') {
                    continue;
                }
                if (visited[next_x][next_y][1]) {
                    continue;
                }
                if (next_x == N - 1 && next_y == M - 1) {
                    return;
                }
                visited[next_x][next_y][1] = true;
                bfs_queue[1].push(make_pair(next_x, next_y));
            }
        }

        if (bfs_queue[0].empty() && bfs_queue[1].empty()) {
            ans = -1;
            return;
        }
    }
}

int main() {
    fastio;

    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        cin >> board[row];
    }

    bfs();

    cout << ans << '\n';

    return 0;
}