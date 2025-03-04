// Solve 2023-02-08
// Update 2025-03-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    const ll MOD = 1e12;
    ll ans = 1;

    for (ll i = 2; i <= n; i++) {
        ans *= i;

        while (ans % 10 == 0) {
            ans /= 10;
        }

        ans %= MOD;
    }

    ans %= 100000;

    SETW(5, '0');
    cout << ans << '\n';

    // 기본 아이디어는 쉬워보이는 듯 했지만, 실제 코드를 짜보면 되게 빡빡한 문제이다.
    // MOD 값을 너무 높이면 오버플로우가 발생하여 정확한 답이 나오지 않으며,
    // 반대로 MOD 값을 너무 낮추면 5의 거듭제곱이 곱해질 때 0의 개수가 한번에 많이 지워지면서 정확한 답이 나오지 않게 된다.

    // 따라서 C++ 기준으로, MOD 값을 10^11이나 10^13으로 설정하면 통과되지 않으며,
    // MOD 값을 10^12로 설정하는 경우에만 풀이가 통과되는 듯 하다.

    return 0;
}
