#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, max;
    cin >> n;

    int arr[100000];
    int DP[100000];
    cin >> arr[0];
    DP[0] = arr[0];
    max = arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (DP[i - 1] < 0) {
            DP[i] = arr[i];
        }
        else {
            DP[i] = DP[i - 1] + arr[i];
        }

        if (DP[i] > max) {
            max = DP[i];
        }
    }

    cout << max << '\n';

    // DP[0] = arr[0]
    // DP[1] = max(arr[0]+arr[1], arr[1])
    // DP[2] = max(arr[0]+arr[1]+arr[2], arr[1]+arr[2], arr[2])

    // max = max(DP[0], DP[1], DP[2])
    // 즉, DP[0]부터 DP[2]까지 계산하고 그 중에서 최댓값을 구한다면
    // 부분합의 모든 경우를 비교해서 최댓값을 구한 것과 같은 것이다.

    return 0;
}