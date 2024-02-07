// Solve 2024-02-07

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

    int board[100][100];

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    int four[2][2] = { { 0, 1 }, { 2, 3 } };
    bool top_bottom = false;
    bool left_right = false;
    int rotate = 0;

    for (int i = 0; i < r; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            if (rotate & 1) {
                left_right = !left_right;
            }
            else {
                top_bottom = !top_bottom;
            }

            swap(four[0][0], four[1][0]);
            swap(four[0][1], four[1][1]);
        }
        else if (cmd == 2) {
            if (rotate & 1) {
                top_bottom = !top_bottom;
            }
            else {
                left_right = !left_right;
            }

            swap(four[0][0], four[0][1]);
            swap(four[1][0], four[1][1]);
        }
        else if (cmd == 3) {
            if (++rotate == 4) {
                rotate = 0;
            }

            int tmp = four[0][0];
            four[0][0] = four[1][0];
            four[1][0] = four[1][1];
            four[1][1] = four[0][1];
            four[0][1] = tmp;
        }
        else if (cmd == 4) {
            if (--rotate == -1) {
                rotate = 3;
            }

            int tmp = four[0][0];
            four[0][0] = four[0][1];
            four[0][1] = four[1][1];
            four[1][1] = four[1][0];
            four[1][0] = tmp;
        }
        else if (cmd == 5) {
            int tmp = four[0][0];
            four[0][0] = four[1][0];
            four[1][0] = four[1][1];
            four[1][1] = four[0][1];
            four[0][1] = tmp;
        }
        else {
            int tmp = four[0][0];
            four[0][0] = four[0][1];
            four[0][1] = four[1][1];
            four[1][1] = four[1][0];
            four[1][0] = tmp;
        }
    }

    int n2 = n / 2;
    int m2 = m / 2;

    if (left_right) {
        for (int x = 0; x < n; x++) {
            reverse(board[x], board[x] + m2);
            reverse(board[x] + m2, board[x] + m);
        }
    }

    if (top_bottom) {
        reverse(board, board + n2);
        reverse(board + n2, board + n);
    }

    int board1[4][50][50];

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            board1[0][x][y] = board[x][y];
            board1[1][x][y] = board[x][y + m2];
            board1[2][x][y] = board[x + n2][y];
            board1[3][x][y] = board[x + n2][y + m2];
        }
    }

    int board2[4][50][50];

    if (rotate == 1) {
        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                board2[0][y][n2 - 1 - x] = board1[0][x][y];
                board2[1][y][n2 - 1 - x] = board1[1][x][y];
                board2[2][y][n2 - 1 - x] = board1[2][x][y];
                board2[3][y][n2 - 1 - x] = board1[3][x][y];
            }
        }

        swap(n, m);
        swap(n2, m2);
    }
    else if (rotate == 2) {
        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                board2[0][n2 - 1 - x][m2 - 1 - y] = board1[0][x][y];
                board2[1][n2 - 1 - x][m2 - 1 - y] = board1[1][x][y];
                board2[2][n2 - 1 - x][m2 - 1 - y] = board1[2][x][y];
                board2[3][n2 - 1 - x][m2 - 1 - y] = board1[3][x][y];
            }
        }
    }
    else if (rotate == 3) {
        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                board2[0][m2 - 1 - y][x] = board1[0][x][y];
                board2[1][m2 - 1 - y][x] = board1[1][x][y];
                board2[2][m2 - 1 - y][x] = board1[2][x][y];
                board2[3][m2 - 1 - y][x] = board1[3][x][y];
            }
        }

        swap(n, m);
        swap(n2, m2);
    }
    else {
        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                board2[0][x][y] = board1[0][x][y];
                board2[1][x][y] = board1[1][x][y];
                board2[2][x][y] = board1[2][x][y];
                board2[3][x][y] = board1[3][x][y];
            }
        }
    }

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cout << board2[four[0][0]][x][y] << ' ';
        }

        for (int y = 0; y < m2; y++) {
            cout << board2[four[0][1]][x][y] << ' ';
        }

        cout << '\n';
    }

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < m2; y++) {
            cout << board2[four[1][0]][x][y] << ' ';
        }

        for (int y = 0; y < m2; y++) {
            cout << board2[four[1][1]][x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
