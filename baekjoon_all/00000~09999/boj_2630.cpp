#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, ans[2];
int board[128][128];

void input() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }
}

void solve(int y0, int x0, int size) {
    bool flag_all_is_same = true;

    for (int y = y0; y < y0 + size; y++) {
        for (int x = x0; x < x0 + size; x++) {
            if (board[y][x] != board[y0][x0]) {
                flag_all_is_same = false;
                break;
            }
        }
        if (!flag_all_is_same) {
            break;
        }
    }

    if (flag_all_is_same) {
        ans[board[y0][x0]]++;
    }
    else {
        int half_size = size / 2;
        solve(y0, x0, half_size);
        solve(y0, x0 + half_size, half_size);
        solve(y0 + half_size, x0, half_size);
        solve(y0 + half_size, x0 + half_size, half_size);
    }
}

int main() {
    fastio;

    input();

    solve(0, 0, N);

    for (int i = 0; i < 2; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}