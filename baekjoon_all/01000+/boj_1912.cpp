// Solve 2022-06-03
// Update 2025-11-06

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

    int cur = 0;
    int mx = -INF;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cur += v;
        if (cur > mx) mx = cur;
        if (cur < 0) cur = 0;
    }

    cout << mx << '\n';
    return 0;
}
