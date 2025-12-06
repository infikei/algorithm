// Solve 2025-12-05

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

    int d, p, q;
    cin >> d >> p >> q;

    if (p < q) swap(p, q);

    int mn = min((d - 1 + p) / p * p, (d - 1 + q) / q * q);

    for (int i = 0; i < q; i++) {
        int a = i * p;
        int b = (d - a - 1 + q) / q * q;

        if (b <= 0) break;

        mn = min(mn, a + b);
    }

    cout << mn << '\n';
    return 0;
}
