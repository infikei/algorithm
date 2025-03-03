// Solve 2022-12-07
// Update 2025-03-03

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

    ll n, k;
    cin >> n >> k;

    ll low = 0, high = 10000000000LL;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;

        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        if (cnt < k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << high << '\n';

    return 0;
}
