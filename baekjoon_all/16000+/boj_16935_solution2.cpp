// Solve 2024-02-07
// Update 2024-02-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    int n2 = n / 2;
    int m2 = m / 2;
    int board[4][50][50];
    int new_board[4][50][50];

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cin >> board[0][x][y];
        }

        for (int y = 0; y < m2; y++) {
            cin >> board[1][x][y];
        }
    }

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cin >> board[2][x][y];
        }

        for (int y = 0; y < m2; y++) {
            cin >> board[3][x][y];
        }
    }

    bool vertical_reverse = false;
    bool horizontal_reverse = false;
    int rotate_cnt = 0;
    int four[4] = { 0, 1, 2, 3 };

    while (r-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            // 상하 반전
            if (rotate_cnt & 1) {
                horizontal_reverse = !horizontal_reverse;
            }
            else {
                vertical_reverse = !vertical_reverse;
            }

            swap(four[0], four[2]);
            swap(four[1], four[3]);
        }
        else if (cmd == 2) {
            // 좌우 반전
            if (rotate_cnt & 1) {
                vertical_reverse = !vertical_reverse;
            }
            else {
                horizontal_reverse = !horizontal_reverse;
            }

            swap(four[0], four[1]);
            swap(four[2], four[3]);
        }
        else if (cmd == 3) {
            // 오른쪽으로 90도 회전
            if (++rotate_cnt == 4) {
                rotate_cnt = 0;
            }

            swap(four[1], four[0]);
            swap(four[0], four[2]);
            swap(four[2], four[3]);
        }
        else if (cmd == 4) {
            // 왼쪽으로 90도 회전
            if (--rotate_cnt == -1) {
                rotate_cnt = 3;
            }

            swap(four[2], four[3]);
            swap(four[0], four[2]);
            swap(four[1], four[0]);
        }
        else if (cmd == 5) {
            // 사분면의 위치를 시계 방향으로 이동
            swap(four[1], four[0]);
            swap(four[0], four[2]);
            swap(four[2], four[3]);
        }
        else {
            // 사분면의 위치를 반시계 방향으로 이동
            swap(four[2], four[3]);
            swap(four[0], four[2]);
            swap(four[1], four[0]);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (four[i] == 0) {
            swap(new_board[i], board[0]);
        }
        else if (four[i] == 1) {
            swap(new_board[i], board[1]);
        }
        else if (four[i] == 2) {
            swap(new_board[i], board[2]);
        }
        else {
            swap(new_board[i], board[3]);
        }
    }

    // 사분면의 위치 이동은 이미 위에서 모두 처리했다.
    // 이제 사분면의 위치 이동 없이, 각각의 사분면 내부에서 상하 반전, 좌우 반전, 회전을 처리한다.

    // 각각의 사분면 내부에서 상하 반전

    if (vertical_reverse) {
        for (int i = 0; i < 4; i++) {
            reverse(new_board[i], new_board[i] + n2);
        }
    }

    // 각각의 사분면 내부에서 좌우 반전

    if (horizontal_reverse) {
        for (int i = 0; i < 4; i++) {
            for (int x = 0; x < n2; x++) {
                reverse(new_board[i][x], new_board[i][x] + m2);
            }
        }
    }

    // 각각의 사분면 내부에서 회전

    if (rotate_cnt == 1) {
        for (int i = 0; i < 4; i++) {
            for (int x = 0; x < n2; x++) {
                for (int y = 0; y < m2; y++) {
                    board[i][y][n2 - 1 - x] = new_board[i][x][y];
                }
            }
        }

        swap(n, m);
        swap(n2, m2);
    }
    else if (rotate_cnt == 2) {
        for (int i = 0; i < 4; i++) {
            for (int x = 0; x < n2; x++) {
                for (int y = 0; y < m2; y++) {
                    board[i][n2 - 1 - x][m2 - 1 - y] = new_board[i][x][y];
                }
            }
        }
    }
    else if (rotate_cnt == 3) {
        for (int i = 0; i < 4; i++) {
            for (int x = 0; x < n2; x++) {
                for (int y = 0; y < m2; y++) {
                    board[i][m2 - 1 - y][x] = new_board[i][x][y];
                }
            }
        }

        swap(n, m);
        swap(n2, m2);
    }
    else {
        swap(board, new_board);
    }

    // 배열 출력

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cout << board[0][x][y] << ' ';
        }

        for (int y = 0; y < m2; y++) {
            cout << board[1][x][y] << ' ';
        }

        cout << '\n';
    }

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cout << board[2][x][y] << ' ';
        }

        for (int y = 0; y < m2; y++) {
            cout << board[3][x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
