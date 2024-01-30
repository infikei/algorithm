// Solve 2024-01-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool is_in_board(int x, int y) {
    return x >= 1 && x <= 19 && y >= 1 && y <= 19;
}

int main() {
    FASTIO;

    int board[20][20] = { 0 };

    for (int x = 1; x <= 19; x++) {
        for (int y = 1; y <= 19; y++) {
            cin >> board[x][y];
        }
    }

    int dx[4] = { -1, 0, 1, 1 };
    int dy[4] = { 1, 1, 1, 0 };
    int ans = 0;
    int ans_x = 0;
    int ans_y = 0;

    // 모든 위치에 대해서 조사한다.
    for (int x = 1; x <= 19; x++) {
        for (int y = 1; y <= 19; y++) {
            // 현재 위치에 알이 놓이지 않은 경우, 탐색하지 않고 skip한다.
            if (board[x][y] == 0) continue;

            // 각 위치마다 4가지 방향에 대해서 탐색한다. (우상, 우, 우하, 하)
            for (int d = 0; d < 4; d++) {
                // 선택된 방향으로 4번째 다음 위치가 보드 밖인 경우 탐색하지 않고 skip한다.
                if (!is_in_board(x + dx[d] * 4, y + dy[d] * 4)) continue;

                bool is_five = true;
                int nx = x;
                int ny = y;

                // 현재 위치에서 선택된 방향으로 4번째 다음 위치까지 같은 알이 놓여있는지 조사한다.
                for (int k = 1; k <= 4; k++) {
                    nx += dx[d];
                    ny += dy[d];

                    if (board[x][y] != board[nx][ny]) {
                        is_five = false;
                        break;
                    }
                }

                if (!is_five) continue;

                // 현재 위치에서 선택된 방향으로 5번째 다음 위치에 같은 알이 놓여있는 경우, 6목이므로 skip한다.
                nx = x + dx[d] * 5;
                ny = y + dy[d] * 5;

                if (is_in_board(nx, ny) && board[x][y] == board[nx][ny]) {
                    continue;
                }

                // 현재 위치에서 선택된 방향의 반대 방향으로 같은 알이 놓여있는 경우, 이 또한 6목이므로 skip한다.
                nx = x - dx[d];
                ny = y - dy[d];

                if (is_in_board(nx, ny) && board[x][y] == board[nx][ny]) {
                    continue;
                }

                // 위의 모든 case에 해당하지 않는 경우, 완전한 5목이므로 답과 위치를 저장하고 모든 반복문을 탈출한다.
                ans = board[x][y];
                ans_x = x;
                ans_y = y;
                break;
            }

            if (ans != 0) break;
        }

        if (ans != 0) break;
    }

    cout << ans << '\n';

    if (ans != 0) {
        cout << ans_x << ' ' << ans_y << '\n';
    }

    return 0;
}
