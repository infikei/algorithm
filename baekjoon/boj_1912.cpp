#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n, max;
    cin >> n;

    int arr[100000];
    int dp[100000];
    cin >> arr[0];
    dp[0] = arr[0];
    max = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (dp[i - 1] < 0)
        {
            dp[i] = arr[i];
        }
        else
        {
            dp[i] = dp[i - 1] + arr[i];
        }

        if (dp[i] > max)
        {
            max = dp[i];
        }
    }

    cout << max << "\n";

    // dp[0] = arr[0]
    // dp[1] = max(arr[0]+arr[1], arr[1])
    // dp[2] = max(arr[0]+arr[1]+arr[2], arr[1]+arr[2], arr[2])

    // max = max(dp[0], dp[1], dp[2])
    // 즉, dp[0]부터 dp[2]까지 계산하고 그 중에서 최댓값을 구한다면
    // 부분합의 모든 경우를 비교해서 최댓값을 구한 것과 같은 것이다.

    return 0;
}