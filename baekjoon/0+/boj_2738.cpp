#include <iostream>
using namespace std;

int A[100][100];
int B[100][100];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> A[row][col];
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> B[row][col];
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cout << A[row][col] + B[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}