#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int main() {
    fastio;

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