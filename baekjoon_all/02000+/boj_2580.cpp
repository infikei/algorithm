// Solve 2022-08-01
// Update 2024-03-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[9][9];
bool board_fixed[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool square_check[3][3][10];

bool recur(int depth = 0) {
    if (depth == 81) return true;

    int x = depth / 9;
    int y = depth % 9;

    if (board_fixed[x][y]) {
        if (recur(depth + 1)) {
            return true;
        }

        return false;
    }

    for (int cur_num = 1; cur_num <= 9; cur_num++) {
        if (row_check[x][cur_num] || col_check[y][cur_num] || square_check[x / 3][y / 3][cur_num]) {
            continue;
        }

        row_check[x][cur_num] = true;
        col_check[y][cur_num] = true;
        square_check[x / 3][y / 3][cur_num] = true;
        board[x][y] = cur_num;

        if (recur(depth + 1)) {
            return true;
        }

        row_check[x][cur_num] = false;
        col_check[y][cur_num] = false;
        square_check[x / 3][y / 3][cur_num] = false;
    }

    return false;
}

int main() {
    FASTIO;

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cin >> board[x][y];

            if (board[x][y] > 0) {
                board_fixed[x][y] = true;
                row_check[x][board[x][y]] = true;
                col_check[y][board[x][y]] = true;
                square_check[x / 3][y / 3][board[x][y]] = true;
            }
        }
    }

    recur();

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cout << board[x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
