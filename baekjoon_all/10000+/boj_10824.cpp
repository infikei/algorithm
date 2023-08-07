// Solve 2022-08-22
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = stoll(a + b) + stoll(c + d);

    cout << ans << '\n';

    return 0;
}
