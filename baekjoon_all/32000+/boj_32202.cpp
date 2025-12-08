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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int oo = 1, ox = 1;

    for (int i = 2; i <= n; i++) {
        int nxt_oo = (ox * 2) % MOD;
        int nxt_ox = (oo + nxt_oo) % MOD;
        oo = nxt_oo;
        ox = nxt_ox;
    }

    cout << (oo + ox * 2 % MOD) % MOD << '\n';
    return 0;
}
