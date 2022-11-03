#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pii = pair<int, int>;
using pic = pair<int, char>;

int N, K, L, ans, board[101][101];
int D2[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pii> snake;
queue<pic> change_direction;

void input() {
    cin >> N >> K;
    for (int k = 0; k < K; k++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }
    cin >> L;
    for (int l = 0; l < L; l++) {
        int x;
        char ch;
        cin >> x >> ch;
        change_direction.push(make_pair(x, ch));
    }
}

void solve() {
    int now_direction = 1;
    int now_x = 1, now_y = 1;
    board[1][1] = 1;
    snake.push(make_pair(1, 1));

    while (true) {
        ans++;
        now_x += D2[now_direction][0];
        now_y += D2[now_direction][1];

        if (now_x < 1 || now_x > N || now_y < 1 || now_y > N) {
            return;
        }
        if (board[now_x][now_y] == 1) {
            return;
        }

        if (board[now_x][now_y] == 0) {
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        board[now_x][now_y] = 1;
        snake.push(make_pair(now_x, now_y));

        if (!change_direction.empty() && ans == change_direction.front().first) {
            if (change_direction.front().second == 'L') {
                now_direction = (now_direction + 1) % 4;
            }
            else {
                now_direction = (now_direction + 3) % 4;
            }
            change_direction.pop();
        }
    }
}

int main() {
    fastio;

    input();

    solve();

    cout << ans << '\n';

    return 0;
}