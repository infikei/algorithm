// dp 배열 대신 temp_sum 변수를 사용한 버전

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, max, temp_sum;
    cin >> n;

    int arr[100000];
    cin >> arr[0];
    max = arr[0];
    temp_sum = arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (temp_sum < 0) {
            temp_sum = arr[i];
        }
        else {
            temp_sum += arr[i];
        }

        if (temp_sum > max) {
            max = temp_sum;
        }
    }

    cout << max << '\n';

    // dp[0] = arr[0]
    // dp[1] = max(arr[0]+arr[1], arr[1])
    // dp[2] = max(arr[0]+arr[1]+arr[2], arr[1]+arr[2], arr[2])

    // max = max(dp[0], dp[1], dp[2])
    // 즉, dp[0]부터 dp[2]까지 계산하고 그 중에서 최댓값을 구한다면
    // 부분합의 모든 경우를 비교해서 최댓값을 구한 것과 같은 것이다.

    return 0;
}