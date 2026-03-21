// Solve 2026-03-16

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

int limit[100];
int speed[100];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0, u = 0; i < n; i++) {
        int len, lim;
        cin >> len >> lim;

        while (len-- > 0) {
            limit[u] = lim;
            u++;
        }
    }

    for (int i = 0, u = 0; i < m; i++) {
        int len, spd;
        cin >> len >> spd;

        while (len-- > 0) {
            speed[u] = spd;
            u++;
        }
    }

    int mx = 0;

    for (int u = 0; u < 100; u++) {
        mx = max(mx, speed[u] - limit[u]);
    }

    cout << mx << '\n';
    return 0;
}
