#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int A[100001];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    int M;
    cin >> M;

    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (binary_search(A, A + N, temp))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}