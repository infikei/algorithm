// Solve 2025-11-15

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

ll get_val(int n) {
    ll ret = 0;
    int left = 1;

    while (left <= n) {
        int val = n / left;
        int right = n / val;
        ret += (ll) (left + right) * (right - left + 1) / 2 * val;
        left = right + 1;
    }

    return ret;
}

int main() {
    FASTIO;

    int l, r;
    cin >> l >> r;
    cout << get_val(r) - get_val(l - 1) << '\n';
    return 0;
}
