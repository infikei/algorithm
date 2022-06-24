#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, K;
    cin >> N >> K;

    int arr[100001];
    arr[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int max = arr[K] - arr[0];
    for (int i = 1; i <= N - K; i++) {
        if (arr[i + K] - arr[i] > max) {
            max = arr[i + K] - arr[i];
        }
    }

    cout << max << "\n";

    return 0;
}