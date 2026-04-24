// Solve 2026-04-11

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

ll f[1000010];
ll a[1000010];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 2] + f[i - 1]) % MOD;
    }

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;

        a[l] = (a[l] + 1) % MOD;
        a[r + 1] = (a[r + 1] - f[r - l + 2] + MOD) % MOD;
        a[r + 2] = (a[r + 2] - f[r - l + 1] + MOD) % MOD;
    }

    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 2] + a[i - 1] + a[i]) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
    return 0;
}
