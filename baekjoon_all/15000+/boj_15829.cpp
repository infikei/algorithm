// Solve 2022-06-10
// Update 2023-06-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1234567891;
const ll r = 31;

int main() {
    FASTIO;

    ll s_length;
    string s;
    cin >> s_length >> s;

    ll ans = 0;

    for (int i = s_length - 1; i >= 0; i--) {
        ans *= r;
        ans += s[i] - 'a' + 1;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
