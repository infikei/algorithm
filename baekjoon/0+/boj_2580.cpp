#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int SIZE = 9;
int board[SIZE][SIZE];
vector<pii> board_blank;
bool solved = false;

void sudoku_input() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cin >> board[row][col];
            if (board[row][col] == 0) {
                board_blank.push_back(make_pair(row, col));
            }
        }
    }
}

bool sudoku_check(int x, int y, int val) {
    for (int col = 0; col < SIZE; col++) {
        if (board[x][col] == val) {
            return false;
        }
    }
    for (int row = 0; row < SIZE; row++) {
        if (board[row][y] == val) {
            return false;
        }
    }
    for (int row = x / 3 * 3; row < x / 3 * 3 + 3; row++) {
        for (int col = y / 3 * 3; col < y / 3 * 3 + 3; col++) {
            if (board[row][col] == val) {
                return false;
            }
        }
    }
    return true;
}

void sudoku_solve(int depth = 0) {
    if (depth == board_blank.size()) {
        solved = true;
        return;
    }

    int x = board_blank[depth].first;
    int y = board_blank[depth].second;
    for (int val = 1; val <= 9; val++) {
        if (sudoku_check(x, y, val)) {
            board[x][y] = val;
            sudoku_solve(depth + 1);
            if (!solved) {
                board[x][y] = 0;
            }
        }
    }
}

void sudoku_print() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << board[row][col] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    sudoku_input();

    sudoku_solve();

    sudoku_print();

    return 0;
}