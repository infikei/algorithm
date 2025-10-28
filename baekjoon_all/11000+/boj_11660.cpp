// Solve 2022-07-22
// Update 2025-10-28

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

int prefix_sum[1025][1025];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int v;
            cin >> v;
            prefix_sum[x][y] = v + prefix_sum[x][y - 1] - prefix_sum[x - 1][y - 1] + prefix_sum[x - 1][y];
        }
    }

    while (q-- > 0) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1] - prefix_sum[x1 - 1][y2] << '\n';
    }

    return 0;
}
