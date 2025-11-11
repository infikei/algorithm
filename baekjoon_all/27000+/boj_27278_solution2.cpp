// Solve 2025-11-10

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

int t[100001];
int s[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        s[i] = s[i - 1] + t[i];
    }

    int mx = 0;

    while (m-- > 0) {
        int u, v, w;
        cin >> u >> v >> w;

        int a = (w - s[u - 1] + s[n] - 1) / s[n] * s[n] + s[u - 1];

        if (u < v) {
            a += s[v - 1] - s[u - 1];
        }
        else {
            a += s[n] - s[u - 1] + s[v - 1];
        }

        mx = max(mx, a);
    }

    cout << mx << '\n';
    return 0;
}
