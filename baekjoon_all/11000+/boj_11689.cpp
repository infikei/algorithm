// Solve 2023-01-21
// Update 2023-09-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    // Euler phi function을 이용하여 계산한다.

    ll cnt = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt -= cnt / i;

            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // 위 과정 이후 n은 1 또는 소수가 되는데, 소수일 경우에는 한 번 더 계산을 진행해야 한다.

    if (n > 1) cnt -= cnt / n;

    // 결과를 출력한다.

    cout << cnt << '\n';

    return 0;
}
