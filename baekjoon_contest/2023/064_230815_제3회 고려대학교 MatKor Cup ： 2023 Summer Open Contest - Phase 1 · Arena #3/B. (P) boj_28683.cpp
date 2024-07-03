// Solve 2023-08-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int solve(const ll n) {
    ll sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n == n) return -1;

    int cnt = 0;

    for (ll a = 1, ae = sqrt(n / 2 + 1); a <= ae; a++) {
        ll b = sqrt(n - a * a);

        if (a * a + b * b == n) cnt++;
    }

    for (ll a = 1; a <= sqrt_n; a++) {
        ll b = n / a;
        if (a * b != n) continue;

        if (a % 2 == b % 2) cnt++;
    }

    return cnt;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    int ans = solve(n);

    cout << ans << '\n';

    return 0;
}
