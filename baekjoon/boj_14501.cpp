#include <iostream>
using namespace std;

int t_arr[16];
int p_arr[16];
int DP[16];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t_arr[i] >> p_arr[i];
    }

    int ans = 0;
    DP[n] = 0;

    for (int i = n; i >= 1; i--) {
        DP[i] = 0;
        for (int j = i + t_arr[i]; j <= n + 1; j++) {
            DP[i] = max(DP[i], DP[j] + p_arr[i]);
        }
        ans = max(ans, DP[i]);
    }

    cout << ans << '\n';

    return 0;
}