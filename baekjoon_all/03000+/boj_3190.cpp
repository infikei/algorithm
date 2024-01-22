// Solve 2022-11-04
// Update 2024-01-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int board[101][101];
int n, k, l;
int cur_time = 0;
int cur_direction = 0;
queue<pii> snake;
queue<pic> change_direction;

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int x;
        char ch;
        cin >> x >> ch;
        change_direction.emplace(x, ch);
    }

    int cur_x = 1;
    int cur_y = 1;

    snake.emplace(1, 1);
    board[1][1] = 1;

    while (true) {
        cur_time++;
        cur_x += dx[cur_direction];
        cur_y += dy[cur_direction];

        if (cur_x < 1 || cur_x > n || cur_y < 1 || cur_y > n) {
            break;
        }

        if (board[cur_x][cur_y] == 1) {
            break;
        }

        if (board[cur_x][cur_y] == 0) {
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        board[cur_x][cur_y] = 1;
        snake.emplace(cur_x, cur_y);

        if (!change_direction.empty() && cur_time == change_direction.front().first) {
            if (change_direction.front().second == 'L') {
                if (--cur_direction == -1) {
                    cur_direction = 3;
                }
            }
            else {
                if (++cur_direction == 4) {
                    cur_direction = 0;
                }
            }

            change_direction.pop();
        }
    }

    cout << cur_time << '\n';

    return 0;
}
