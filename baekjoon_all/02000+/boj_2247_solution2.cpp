// Solve 2025-01-26
// Update 2025-11-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    cin >> n;
    ll ans = 0;
    ll left = 2;

    while (left <= n) {
        ll cnt = n / left;
        ll right = n / cnt;
        ll sum = (left + right) * (right - left + 1) / 2;
        ans += sum * (cnt - 1);
        ans %= 1000000;

        left = right + 1;
    }

    cout << ans << '\n';
    return 0;
}
