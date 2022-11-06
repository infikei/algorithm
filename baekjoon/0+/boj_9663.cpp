#include <iostream>
using namespace std;

int board[15];
int N, ans;

bool check(int row) {
    for (int i = 1; i < row; i++) {
        if (board[row] == board[i] || abs(board[row] - board[i]) == row - i) {
            return false;
        }
    }
    return true;
}

void n_queens(int row = 1) {
    if (row == N + 1) {
        ans++;
    }

    else {
        for (int i = 1; i <= N; i++) {
            board[row] = i;
            if (check(row)) {
                n_queens(row + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    n_queens();

    cout << ans << '\n';

    return 0;
}