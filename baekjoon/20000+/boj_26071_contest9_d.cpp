#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    string board_each_row;
    int left_idx = N - 1, right_idx = 0, top_idx = N - 1, bottom_idx = 0;

    for (int row = 0; row < N; row++) {
        cin >> board_each_row;

        int tmp_left_idx = N - 1, tmp_right_idx = 0;
        for (int col = 0; col < N; col++) {
            if (board_each_row[col] == 'G') {
                tmp_left_idx = min(tmp_left_idx, col);
                tmp_right_idx = max(tmp_right_idx, col);
            }
        }

        // when G exists in board_each_row
        if (tmp_left_idx <= tmp_right_idx) {
            left_idx = min(left_idx, tmp_left_idx);
            right_idx = max(right_idx, tmp_right_idx);
            top_idx = min(top_idx, row);
            bottom_idx = max(bottom_idx, row);
        }
    }

    int ans = 0;
    if (top_idx < bottom_idx) {
        ans += min(bottom_idx, N - 1 - top_idx);
    }
    if (left_idx < right_idx) {
        ans += min(right_idx, N - 1 - left_idx);
    }
    cout << ans << '\n';

    return 0;
}