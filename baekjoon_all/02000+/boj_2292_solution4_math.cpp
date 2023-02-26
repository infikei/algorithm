// Solve 2023-02-08
// Update 2023-02-26

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = sqrt((n * 4.0 - 1) / 12) - 1;
    ans = max(ans, 1);
    while (n > (ans * ans - ans) * 3 + 1) {
        ans++;
    }
    cout << ans << '\n';

    // 27436번의 풀이를 가져와서 작성함

    // input -> output
    // 1 -> 1
    // 2 ~ 7 -> 2
    // 8 ~ 19 -> 3
    // 20 ~ 37 -> 4
    // 38 ~ 61 -> 5
    // 62 ~ 91 -> 6
    // ...

    // 위의 규칙을 봤을 때, input이 n이면 아래의 1번 식을 만족하는 x의 최솟값이 output이 된다.
    // n <= (1 + ... + (x-1)) * 6 + 1 (1번 식)

    // 1번 식을 x에 관하여 정리하면,
    // n <= x(x-1)/2*6 + 1
    // n <= 3x(x-1) + 1
    // (n-1)/3 <= x^2 - x
    // (n-1)/3 + 1/4 <= (x - 1/2)^2
    // sqrt( (4n-1)/12 ) <= x - 1/2
    // sqrt( (4n-1)/12 ) + 1/2 <= x (2번 식)
    // 즉, 2번 식을 만족하는 x의 최솟값이 output이 된다.

    // 이제, 부동소수점 오차를 감안하여 근삿값을 조금 더 작게 잡은 후,
    // 부동소수점 오차를 걱정할 필요가 없는 1번 식을 활용하여 정확한 답을 구한다.

    return 0;
}