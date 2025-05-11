// Solve 2025-05-11

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

    ll ans = 0;
    ll pow = 2;

    while (n > 0) {
        ans += (n + 1) / 2 * pow;
        n /= 2;
        pow *= 2;
    }

    cout << ans << '\n';

    return 0;
}
