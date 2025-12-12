// Solve 2025-12-10

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

    int n, m;
    cin >> n >> m;

    int positive_len = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        positive_len += h + 1;
    }

    int negative_len = max(0, m - positive_len);
    n++;
    int q = negative_len / n;
    int r = negative_len % n;

    int ans = q * (q + 1) / 2 * (q + q + 1) / 3 * n;
    ans += (q + 1) * (q + 1) * r;
    cout << ans << '\n';
    return 0;
}
