#include <iostream>
#include <string>
using namespace std;

int board[50][50];
int N, M, ans;

void input() {
    cin >> N >> M;

    string row;
    for (int i = 0; i < N; i++) {
        cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j];
        }
    }
}

bool check(int x, int y, int size) {
    if (board[x][y] == board[x][y + size - 1] && board[x][y] == board[x + size - 1][y] && board[x][y] == board[x + size - 1][y + size - 1]) {
        return true;
    }
    else {
        return false;
    }
}

int maximum_square() {
    for (int size = min(N, M); size >= 2; size--) {
        for (int i = 0; i < N - size + 1; i++) {
            for (int j = 0; j < M - size + 1; j++) {
                if (check(i, j, size)) {
                    return size * size;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    ans = maximum_square();

    cout << ans << '\n';

    return 0;
}