#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, Drow[4] = {0, 0, 1, 1}, Dcol[4] = {0, 1, 0, 1};
string board[64], ans;

void input() {
    cin >> N;
    for (int row = 0; row < N; row++) {
        cin >> board[row];
    }
}

void solve(int row0, int col0, int size) {
    bool flag_all_is_same = true;

    for (int row = row0; row < row0 + size; row++) {
        for (int col = col0; col < col0 + size; col++) {
            if (board[row][col] != board[row0][col0]) {
                flag_all_is_same = false;
                break;
            }
        }
        if (!flag_all_is_same) {
            break;
        }
    }

    if (flag_all_is_same) {
        ans += board[row0][col0];
    }
    else {
        int half_size = size / 2;
        ans += '(';
        for (int i = 0; i < 4; i++) {
            solve(row0 + half_size * Drow[i], col0 + half_size * Dcol[i], half_size);
        }
        ans += ')';
    }
}

int main() {
    fastio;

    input();

    solve(0, 0, N);

    cout << ans << '\n';

    return 0;
}