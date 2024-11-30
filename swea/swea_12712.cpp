// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int n, m;
        cin >> n >> m;

        int board[15][15];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cin >> board[x][y];
            }
        }

        int answer = 0;

        for (int cx = 0; cx < n; cx++) {
            for (int cy = 0; cy < n; cy++) {
                // + 모양으로 스프레이를 뿌린 경우
                int value = -board[cx][cy];

                for (int diff = -m + 1; diff < m; diff++) {
                    int x = cx + diff;

                    if (x >= 0 && x < n) {
                        value += board[x][cy];
                    }

                    int y = cy + diff;

                    if (y >= 0 && y < n) {
                        value += board[cx][y];
                    }
                }

                if (value > answer) {
                    answer = value;
                }

                // x 모양으로 스프레이를 뿌린 경우

                value = -board[cx][cy];

                for (int diff = -m + 1; diff < m; diff++) {
                    int x = cx + diff;
                    int y = cy + diff;

                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        value += board[x][y];
                    }

                    x = cx - diff;

                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        value += board[x][y];
                    }
                }

                if (value > answer) {
                    answer = value;
                }
            }
        }

        cout << "#" << test_case << " " << answer << '\n';
    }

    return 0;
}
