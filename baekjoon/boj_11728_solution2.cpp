#include <iostream>
using namespace std;

int N, M;
int A[1000000], B[1000000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int pt_A = 0, pt_B = 0; // 포인터
    while (pt_A < N && pt_B < M) {
        if (A[pt_A] > B[pt_B]) {
            cout << B[pt_B] << ' ';
            pt_B++;
        }
        else {
            cout << A[pt_A] << ' ';
            pt_A++;
        }
    }
    while (pt_A < N) {
        cout << A[pt_A] << ' ';
        pt_A++;
    }
    while (pt_B < M) {
        cout << B[pt_B] << ' ';
        pt_B++;
    }
    cout << '\n';

    return 0;
}