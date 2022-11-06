#include <iostream>
using namespace std;

int sum_matrix[1025][1025];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;

    for (int col = 0; col <= N; col++) {
        sum_matrix[0][col] = 0;
    }

    for (int row = 0; row <= N; row++) {
        sum_matrix[row][0] = 0;
    }

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> sum_matrix[row][col];
            sum_matrix[row][col] += sum_matrix[row][col - 1];
            sum_matrix[row][col] -= sum_matrix[row - 1][col - 1];
            sum_matrix[row][col] += sum_matrix[row - 1][col];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum_matrix[x2][y2] - sum_matrix[x2][y1 - 1] - sum_matrix[x1 - 1][y2] + sum_matrix[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}