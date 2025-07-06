// Solve 2025-07-02

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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int team1 = a + b * 2 + c * 3;
    int team2 = d + e * 2 + f * 3;

    if (team1 > team2) cout << 1 << '\n';
    else if (team1 < team2) cout << 2 << '\n';
    else cout << 0 << '\n';

    return 0;
}
