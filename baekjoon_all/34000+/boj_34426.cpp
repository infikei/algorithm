// Solve 2025-11-07

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

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        double mn = INF;
        int idx = 0;

        for (int j = 1; j <= m; j++) {
            int v, d;
            cin >> v >> d;
            double t = (double) d / v;

            if (t < mn) {
                mn = t;
                idx = j;
            }
        }

        cout << idx << '\n';
    }

    return 0;
}
