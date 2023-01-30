#include <iostream>
using namespace std;

int A[100][100], B[100][100], AB[100][100];
int N, M, K;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력
    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> A[row][col];
        }
    }
    cin >> M >> K;
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < K; col++) {
            cin >> B[row][col];
        }
    }

    // 행렬 곱셈
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < K; col++) {
            AB[row][col] = 0;
            for (int i = 0; i < M; i++) {
                AB[row][col] += A[row][i] * B[i][col];
            }
        }
    }

    // 출력
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < K; col++) {
            cout << AB[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}