// Solve 2025-11-21

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
const int MOD = 1000003;

int a[200010];
int b[200010];
ll fac[MOD];

int get_log2(int x, int y) {
    int ret = 0;

    while (y / 2 >= x) {
        y /= 2;
        ret++;
    }

    return ret;
}

ll mod_pow(ll x, ll p) {
    ll ret = 1;

    while (p) {
        if (p & 1) {
            ret = ret * x % MOD;
        }

        x = x * x % MOD;
        p >>= 1;
    }

    return ret;
}

ll mod_div(ll x) {
    return mod_pow(x, MOD - 2);
}

void init() {
    fac[0] = 1;

    for (ll i = 1; i < MOD; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void solution() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int k = INF;

    for (int i = 0; i < n; i++) {
        k = min(k, get_log2(a[i], b[i]));
    }

    ll cnt = k;
    ll r_sum = 0;
    ll lower = 1;

    for (int i = 0; i < n; i++) {
        int r = (b[i] >> k) - a[i];
        r_sum += r;
        lower = lower * fac[r] % MOD;
    }

    ll upper = (r_sum >= MOD ? 0 : fac[r_sum]);
    ll ans = upper * mod_div(lower) % MOD;
    cnt += r_sum;

    vector<int> c(k);

    for (int i = 0; i < n; i++) {
        int tmp = b[i];

        for (int j = 0; j < k; j++) {
            c[j] += (tmp & 1);
            tmp >>= 1;
        }
    }

    for (int i = 0; i < k; i++) {
        ans = ans * fac[c[i]] % MOD;
        cnt += c[i];
    }

    cout << cnt << ' ' << ans << '\n';
}

int main() {
    FASTIO;

    init();

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
