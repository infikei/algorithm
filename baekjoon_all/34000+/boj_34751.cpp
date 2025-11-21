// Solve 2025-11-20

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
    ll cnt[3] = {0};
    int prv_a = 2;
    int len = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == prv_a) {
            len++;
        }
        else {
            cnt[prv_a] += len * (ll) (len + 1) / 2;
            len = 1;
            prv_a = a;
        }
    }

    cnt[prv_a] += len * (ll) (len + 1) / 2;

    cnt[2] = n * (ll) (n + 1) / 2 - cnt[0] - cnt[1];
    // ll ans = cnt[0] * 1 + cnt[1] * 0 + cnt[2] * 2;
    ll ans = cnt[0] + cnt[2] * 2;
    cout << ans << '\n';
    return 0;
}
