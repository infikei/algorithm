// Solve 2025-11-06

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

ll arr[1 << 18];

int main() {
    FASTIO;

    int n;
    cin >> n;
    int h = __builtin_popcount(n);

    for (int i = (1 << h); i >= 2; i >>= 1) {
        for (int j = i / 2; j <= n; j += i) {
            cin >> arr[j];
        }
    }

    ll mx = -LLINF;

    for (int low = 0; low < h; low++) {
        for (int high = low; high < h; high++) {
            ll cur = 0;

            for (int i = 1; i <= n; i++) {
                int last_bit = 0;

                for (int j = 0; j < h; j++) {
                    if (i & (1 << j)) {
                        last_bit = j;
                        break;
                    }
                }

                if (last_bit < low || last_bit > high) continue;

                cur += arr[i];
                if (cur > mx) mx = cur;
                if (cur < 0) cur = 0;
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
