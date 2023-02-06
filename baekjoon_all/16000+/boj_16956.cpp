#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int R, C, is_possible = 1;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
string board[500];

void solve() {
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (board[row][col] == 'W') {
                for (int i = 0; i < 4; i++) {
                    int row1 = row + dx[i], col1 = col + dy[i];
                    if (row1 < 0 || row1 >= R || col1 < 0 || col1 >= C) {
                        continue;
                    }
                    if (board[row1][col1] == 'W') {
                        continue;
                    }
                    if (board[row1][col1] == 'S') {
                        is_possible = 0;
                        return;
                    }
                    board[row1][col1] = 'D';
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> R >> C;
    for (int row = 0; row < R; row++) {
        cin >> board[row];
    }

    solve();

    cout << is_possible << '\n';
    if (is_possible == 1) {
        for (int row = 0; row < R; row++) {
            cout << board[row] << '\n';
        }
    }

    return 0;
}