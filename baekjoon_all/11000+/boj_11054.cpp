// Solve 2022-07-25
// Update 2023-02-12

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1000;
int n, arr[MAX_N], dp1[MAX_N], dp2[MAX_N];

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 가장 긴 증가하는 부분 수열의 길이 구하기
    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp1[i] = max(dp1[i], dp1[j]);
            }
        }
        dp1[i]++;
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
        ans = max(ans, dp1[i] + dp2[i]);
    }
    ans--;
    cout << ans << '\n';

    return 0;
}