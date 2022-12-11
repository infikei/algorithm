#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int N, M, H, ans, cnt_ripe, cnt_empty, board[100][100][100];
int dz[6] = {0, 0, 0, 0, 1, -1}, dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0};
queue<piii> Q;

int main() {
    fastio;

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                cin >> board[h][row][col];

                if (board[h][row][col] == 1) {
                    cnt_ripe++;
                    Q.push(make_pair(h, make_pair(row, col)));
                }
                else if (board[h][row][col] == -1) {
                    cnt_empty++;
                }
            }
        }
    }

    while (true) {
        int i_end = Q.size();
        for (int i = 0; i < i_end; i++) {
            piii now = Q.front();
            Q.pop();

            for (int j = 0; j < 6; j++) {
                int next_z = now.first + dz[j];
                int next_x = now.second.first + dx[j];
                int next_y = now.second.second + dy[j];
                if (next_z < 0 || next_z >= H || next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
                    continue;
                }
                if (board[next_z][next_x][next_y] == 0) {
                    board[next_z][next_x][next_y] = 1;
                    cnt_ripe++;
                    Q.push(make_pair(next_z, make_pair(next_x, next_y)));
                }
            }
        }

        if (Q.empty()) {
            break;
        }
        ans++;
    }

    if (H * N * M == cnt_ripe + cnt_empty) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}