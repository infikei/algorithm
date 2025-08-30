// Solve 2025-08-29

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

    int a, t, bd;
    cin >> a >> t >> bd;

    int b = 1;
    int s = 4;

    while (t > s) {
        s += b + 4;
        b++;
    }

    b--;
    s -= b + 4;
    int ans = s * 2;

    if (t == s + 1) {
        ans += bd;
    }
    else if (t == s + 2) {
        ans += 2 + bd;
    }
    else {
        ans += 4 + (bd == 0 ? 0 : b + 2) + (t - (s + 3));
    }

    cout << ans % a << '\n';
    return 0;
}
