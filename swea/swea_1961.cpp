// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;

        int board[7][7];

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cin >> board[row][col];
            }
        }

        int board_90[7][7];
        int board_180[7][7];
        int board_270[7][7];

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                board_90[row][col] = board[n - 1 - col][row];
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                board_180[row][col] = board[n - 1 - row][n - 1 - col];
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                board_270[row][col] = board[col][n - 1 - row];
            }
        }

        cout << "#" << test_case << '\n';

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cout << board_90[row][col];
            }

            cout << " ";

            for (int col = 0; col < n; col++) {
                cout << board_180[row][col];
            }

            cout << " ";

            for (int col = 0; col < n; col++) {
                cout << board_270[row][col];
            }

            cout << '\n';
        }
    }

    return 0;
}
