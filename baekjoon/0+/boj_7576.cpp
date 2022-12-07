#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int N, M, ans, cnt_ripe, cnt_empty, board[1000][1000];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<pii> Q;

int main() {
    fastio;

    cin >> M >> N;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> board[row][col];

            if (board[row][col] == 1) {
                cnt_ripe++;
                Q.push(make_pair(row, col));
            }
            else if (board[row][col] == -1) {
                cnt_empty++;
            }
        }
    }

    while (true) {
        int i_end = Q.size();
        for (int i = 0; i < i_end; i++) {
            pii now = Q.front();
            Q.pop();

            for (int j = 0; j < 4; j++) {
                int next_x = now.first + dx[j];
                int next_y = now.second + dy[j];
                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
                    continue;
                }
                if (board[next_x][next_y] == 0) {
                    board[next_x][next_y] = 1;
                    cnt_ripe++;
                    Q.push(make_pair(next_x, next_y));
                }
            }
        }

        if (Q.empty()) {
            break;
        }
        ans++;
    }

    if (N * M == cnt_ripe + cnt_empty) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}