// Solve 2023-03-06
// Update 2023-11-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<ll> vec(n);

    for (ll &x : vec) {
        cin >> x;
    }

    sort(vec.begin(), vec.end());

    int i = (n >> 1) - 1;
    int j = n >> 1;
    ll tmp = 1;

    if (n & 1) {
        j++;
        tmp = 3;
    }

    ll ans = 0;

    while (i >= 0) {
        ans <<= 1;
        ans %= MOD;
        ans += (vec[j] - vec[i]) * tmp % MOD;
        ans %= MOD;

        tmp <<= 2;
        tmp += 3;
        tmp %= MOD;
        i--;
        j++;
    }

    cout << ans << '\n';

    return 0;
}
