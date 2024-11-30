// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int board[9][9];

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                cin >> board[row][col];
            }
        }

        bool check = true;

        for (int row = 0; row < 9; row++) {
            int count_number[10] = { 0 };

            for (int col = 0; col < 9; col++) {
                int cur_num = board[row][col];
                count_number[cur_num]++;
            }

            for (int i = 1; i <= 9; i++) {
                if (count_number[i] != 1) {
                    check = false;
                    break;
                }
            }

            if (!check) break;
        }

        if (check) {
            for (int col = 0; col < 9; col++) {
                int count_number[10] = { 0 };

                for (int row = 0; row < 9; row++) {
                    int cur_num = board[row][col];
                    count_number[cur_num]++;
                }

                for (int i = 1; i <= 9; i++) {
                    if (count_number[i] != 1) {
                        check = false;
                        break;
                    }
                }

                if (!check) break;
            }
        }

        if (check) {
            for (int row = 0; row < 9; row += 3) {
                for (int col = 0; col < 9; col += 3) {
                    int count_number[10] = { 0 };

                    for (int drow = 0; drow < 3; drow++) {
                        for (int dcol = 0; dcol < 3; dcol++) {
                            int cur_num = board[row + drow][col + dcol];
                            count_number[cur_num]++;
                        }
                    }

                    for (int i = 1; i <= 9; i++) {
                        if (count_number[i] != 1) {
                            check = false;
                            break;
                        }
                    }

                    if (!check) break;
                }

                if (!check) break;
            }
        }

        cout << "#" << test_case << " " << check << '\n';
    }

    return 0;
}
