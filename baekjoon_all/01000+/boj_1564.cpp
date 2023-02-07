// Solve 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    const ll MOD = 1000000000000;
    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0) {
            ans /= 10;
        }
        ans %= MOD;
    }

    ans %= 100000;
    string ans_str = to_string(ans);
    while (SIZE(ans_str) < 5) {
        ans_str = "0" + ans_str;
    }
    cout << ans_str << '\n';

    // 기본 아이디어는 쉬워보이는 듯 했지만, 실제 코드를 짜보면 되게 빡빡한 문제이다.
    // MOD 값을 너무 높이면 오버플로우가 발생하여 정확한 답이 나오지 않으며,
    // 반대로 MOD 값을 너무 낮추면 5의 거듭제곱이 곱해질 때 0의 개수가 한번에 많이 지워지면서 정확한 답이 나오지 않게 된다.

    // 따라서 C++ 기준으로, MOD 값을 10^11이나 10^13으로 설정하면 통과되지 않으며,
    // MOD 값을 10^12로 설정하는 경우에만 풀이가 통과되는 듯 하다.

    return 0;
}