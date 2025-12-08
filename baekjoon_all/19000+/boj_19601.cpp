// Solve 2025-12-08

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

int my_log(ll a, ll b) {
    int ret = -1;

    while (b >= 1) {
        b /= a;
        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        ll n;
        cin >> n;

        int a = my_log(2, n);
        int b = my_log(3, n);
        int c = my_log(3, n / 2);

        cout << a << ' ' << b * 2 + (b == c ? 1 : 0) << '\n';
    }

    return 0;
}
