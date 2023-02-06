#include <iostream>
using namespace std;

int N, M, ans = -100000000;
int graph[100][100];
int sum_row[100], sum_col[100];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> graph[row][col];
            sum_row[row] += graph[row][col];
            sum_col[col] += graph[row][col];
        }
    }

    for (int row = 0; row < N; row++) {
        for (int row2 = row + 1; row2 < N; row2++) {
            for (int col = 0; col < M; col++) {
                for (int col2 = col + 1; col2 < M; col2++) {
                    int now = sum_row[row] + sum_row[row2] + sum_col[col] + sum_col[col2];
                    now = now - graph[row][col] - graph[row][col2] - graph[row2][col] - graph[row2][col2];
                    now += (row2 - row - 1) * (col2 - col - 1);

                    ans = max(ans, now);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}