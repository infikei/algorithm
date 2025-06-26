// Solve 2025-06-24

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

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m, l;
        cin >> n >> m >> l;

        int min_s = m;

        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;

            if (s != -1) {
                min_s = min(min_s, s);
            }
        }

        int after_freeze = max(m - min_s, l);
        cout << "The scoreboard has been frozen with " << after_freeze << " minute" << (after_freeze == 1 ? "" : "s") << " remaining.\n";
    }

    return 0;
}
