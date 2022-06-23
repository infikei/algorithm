#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M, temp = 0, sum = 0;
    cin >> N >> M;

    int arr[100001];
    arr[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        sum += temp;
        arr[i] = sum;
    }

    int begin, end;

    for (int i = 0; i < M; i++) {
        cin >> begin >> end;
        cout << arr[end] - arr[begin - 1] << "\n";
    }

    return 0;
}