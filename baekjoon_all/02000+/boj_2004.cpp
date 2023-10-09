// Solve 2022-06-08
// Update 2023-10-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n, m;
    cin >> n >> m;

    // nCm = n! / m! / (n - m)! 인 것을 이용한다.
    // 즉, 1676번의 방법을 조금만 변형해서 해결할 수 있다.

    ll cnt_5 = 0;

    for (ll i = 5; i <= n; i *= 5) {
        cnt_5 += n / i;
        cnt_5 -= m / i;
        cnt_5 -= (n - m) / i;
    }

    ll cnt_2 = 0;

    for (ll i = 2; i <= n; i *= 2) {
        cnt_2 += n / i;
        cnt_2 -= m / i;
        cnt_2 -= (n - m) / i;
    }

    cout << min(cnt_5, cnt_2) << '\n';

    return 0;
}
