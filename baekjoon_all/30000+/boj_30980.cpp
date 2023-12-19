// Solve 2023-12-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> board(n * 3);

    for (string &row : board) {
        cin >> row;
    }

    int row_end = n * 3;
    int col_end = m * 8;

    for (int row = 0; row < row_end; row += 3) {
        for (int col = 0; col < col_end; col += 8) {
            int a = board[row + 1][col + 1] - '0';
            int b = board[row + 1][col + 3] - '0';
            int len_c;
            int c;

            if (board[row + 1][col + 6] == '.') {
                len_c = 1;
                c = board[row + 1][col + 5] - '0';
            }
            else {
                len_c = 2;
                c = stoi(board[row + 1].substr(col + 5, 2));
            }

            if (a + b == c) {
                board[row + 1][col] = '*';

                if (len_c == 1) {
                    board[row + 1][col + 6] = '*';

                    for (int j = col + 1, je = col + 6; j < je; j++) {
                        board[row][j] = '*';
                        board[row + 2][j] = '*';
                    }
                }
                else {
                    board[row + 1][col + 7] = '*';

                    for (int j = col + 1, je = col + 7; j < je; j++) {
                        board[row][j] = '*';
                        board[row + 2][j] = '*';
                    }
                }
            }
            else {
                board[row][col + 3] = '/';
                board[row + 1][col + 2] = '/';
                board[row + 2][col + 1] = '/';
            }
        }
    }

    for (string &row : board) {
        cout << row << '\n';
    }

    return 0;
}
