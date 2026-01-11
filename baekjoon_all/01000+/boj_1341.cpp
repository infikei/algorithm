// Solve 2026-01-11

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

    ll a, b;
    cin >> a >> b;

    for (int i = 1; i <= 60; i++) {
        ll n = (1LL << i) - 1;

        if (n % b == 0) {
            ll m = a * (n / b);
            string ans;

            for (int j = 0; j < i; j++) {
                ans.push_back(m % 2 == 1 ? '*' : '-');
                m /= 2;
            }

            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
