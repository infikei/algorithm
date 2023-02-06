#include <iostream>
using namespace std;
typedef long long ll;

int N;
int board[100][100];
ll memo[100][100];

void input() {
    cin >> N;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> board[row][col];
        }
    }
}

void solve() {
    for (int row = N - 1; row >= 0; row--) {
        for (int col = N - 1; col >= 0; col--) {
            if (board[row][col] == 0) {
                if (row == N - 1 && col == N - 1) {
                    memo[row][col] = 1;
                }
                else {
                    memo[row][col] = 0;
                }
            }
            else {
                int now = board[row][col];
                if (row + now < N) {
                    memo[row][col] += memo[row + now][col];
                }
                if (col + now < N) {
                    memo[row][col] += memo[row][col + now];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << memo[0][0] << '\n';

    return 0;
}