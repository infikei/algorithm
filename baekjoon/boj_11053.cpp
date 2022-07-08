#include <iostream>
using namespace std;

int arr[1001];
int DP[1001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n;
    cin >> n;

    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    DP[0] = 0;
    DP[1] = 1;
    int ans = 1;

    for (int i = 2; i <= n; i++) {
        DP[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        ans = max(ans, DP[i]);
    }

    cout << ans << "\n";

    return 0;
}