// Solve 2025-10-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

#ifdef BOJ
#define testPrint(x) ((void)0)
using lll = __int128;
using lld = __float128;
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
using lll = long long;
using lld = long double;
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool recur(lll a, lll b, int l, int k, lll p, lll q) {
    if (l == 0) {
        return true;
    }

    lll r = (lll) (ll) pow(3LL, k - 1) * 1000;
    lll r2 = r * 2;
    lll r3 = r * 3;

    if (p > a + r && p < a + r2 && q > b + r && q < b + r2) {
        return false;
    }

    lll na = p >= a + r2 ? a + r2 : p >= a + r ? a + r : a;
    lll nb = q >= b + r2 ? b + r2 : q >= b + r ? b + r : b;
    return recur(na, nb, l - 1, k - 1, p, q);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        ll aa, bb;
        int l, k;
        string pp, qq;
        cin >> aa >> bb >> l >> k >> pp >> qq;

        lll a = (lll) aa * 1000;
        lll b = (lll) bb * 1000;
        int p_sign = pp[0] == '-' ? -1 : 1;
        int q_sign = qq[0] == '-' ? -1 : 1;
        lll p = (lll) stoll(pp.substr(0, size(pp) - 4)) * 1000 + p_sign * stoi(pp.substr(size(pp) - 3, 3));
        lll q = (lll) stoll(qq.substr(0, size(qq) - 4)) * 1000 + q_sign * stoi(qq.substr(size(qq) - 3, 3));
        lll r = (lll) (ll) pow(3LL, k) * 1000;

        if (p < a || p > a + r || q < b || q > b + r) {
            cout << 0 << '\n';
            continue;
        }

        cout << recur(a, b, l, k, p, q) << '\n';
    }

    return 0;
}
