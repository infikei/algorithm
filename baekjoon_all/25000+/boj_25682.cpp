#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, M, K, ans;
int board_cnt[2001][2001];

int main() {
    fastio;

    cin >> N >> M >> K;

    for (int row = 0; row < N; row++) {
        string board_row;
        cin >> board_row;

        for (int col = 0; col < M; col++) {
            board_cnt[row + 1][col + 1] = board_cnt[row][col + 1] - board_cnt[row][col] + board_cnt[row + 1][col];
            if (board_row[col] == 'B') {
                if ((row + col) % 2 == 0) {
                    board_cnt[row + 1][col + 1]++;
                }
            }
            else {
                if ((row + col) % 2 == 1) {
                    board_cnt[row + 1][col + 1]++;
                }
            }
        }
    }

    int KK = K * K;
    ans = KK;

    for (int row = K; row <= N; row++) {
        for (int col = K; col <= M; col++) {
            int area_cnt = board_cnt[row][col] - board_cnt[row][col - K] + board_cnt[row - K][col - K] - board_cnt[row - K][col];
            ans = min(ans, min(area_cnt, KK - area_cnt));
        }
    }

    cout << ans << '\n';

    return 0;
}