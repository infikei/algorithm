// Solve 2026-04-13

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

bool building[31][31];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        memset(building, false, sizeof(building));

        int f, r, n;
        cin >> f >> r >> n;

        while (n-- > 0) {
            int a, b;
            cin >> a >> b;
            building[a][b] = true;
        }

        int mn_dist = f * 2 + r + 1;

        for (int x = 1; x <= f; x++) {
            int mx_dark = 0;
            int cur = 0;

            for (int y = 1; y <= r; y++) {
                if (building[x][y]) {
                    cur = 0;
                }
                else {
                    cur++;
                    mx_dark = max(mx_dark, cur);
                }
            }

            mn_dist += 2 * (r - mx_dark);
        }

        cout << mn_dist << '\n';
    }

    return 0;
}
