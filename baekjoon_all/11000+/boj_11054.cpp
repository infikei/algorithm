// Solve 2022-07-25
// Update 2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[1000], dp[1000], dp2[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 가장 긴 증가하는 부분 수열의 길이 구하기
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }

        dp[i]++;
    }

    // 가장 긴 감소하는 부분 수열의 길이 구하기
    dp2[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                dp2[i] = max(dp2[i], dp2[j]);
            }
        }

        dp2[i]++;
    }

    // 위에서 구한 길이의 합을 통해 답 구하기
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i] + dp2[i]);
    }

    ans--;

    cout << ans << '\n';

    return 0;
}
