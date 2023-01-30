#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int main() {
    fastio;

    ll n;
    cin >> n;

    // Euler phi function을 이용하여 계산한다.
    ll cnt = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt -= cnt / i;
            while (n % i == 0) n /= i;
        }
    }

    // 위 과정 이후 n은 1 또는 소수가 되는데, 소수일 경우에는 한 번 더 계산을 진행해야 한다.
    if (n > 1) cnt -= cnt / n;

    // print result
    cout << cnt << '\n';

    return 0;
}