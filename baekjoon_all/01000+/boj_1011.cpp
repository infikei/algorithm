// Solve 2023-01-25
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        ll x, y;
        cin >> x >> y;

        y -= x;

        // 1 + 2 + ... + n + ... + 2 + 1 = n^2
        // 즉, n^2 칸을 이동하기 위해서는 (2n-1)번 이동해야 한다.
        // 또한 남는 y-n^2(사실은 y-x-n^2) 칸에 대해서는 n으로 나눠준 나머지 값을 이용하여 추가로 더해준다.

        ll n = 1;

        while (n * n <= y) n++;

        n--;

        ll ans = 2 * n - 1 + (y - n * n + n - 1) / n;

        cout << ans << '\n';
    }

    return 0;
}
