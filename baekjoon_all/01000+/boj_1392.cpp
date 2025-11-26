// Solve 2025-11-24

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

int prefix[101];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    while (q-- > 0) {
        int x;
        cin >> x;

        int y = upper_bound(prefix, prefix + n, x) - prefix;
        cout << y << '\n';
    }

    return 0;
}
