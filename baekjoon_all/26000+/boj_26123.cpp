// Solve 2025-11-19

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

int h[300000];

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;
    int mx_h = 0;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        mx_h = max(mx_h, h[i]);
    }

    mx_h = max(0, mx_h - d);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (h[i] > mx_h) {
            ans += h[i] - mx_h;
        }
    }

    cout << ans << '\n';
    return 0;
}
