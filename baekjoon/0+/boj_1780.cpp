#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, ans[3], board[2187][2187];

void input() {
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> board[row][col];
        }
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
        ans[board[row0][col0] + 1]++;
    }
    else {
        int next_size = size / 3;
        for (int i = 0; i < 9; i++) {
            solve(row0 + next_size * (i / 3), col0 + next_size * (i % 3), next_size);
        }
    }
}

int main() {
    fastio;

    input();

    solve(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}