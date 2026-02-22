// Solve 2026-02-18

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

    int x_mn = 10000;
    int x_mx = 0;
    int y_mn = 10000;
    int y_mx = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        x_mn = min(x_mn, x);
        x_mx = max(x_mx, x);
        y_mn = min(y_mn, y);
        y_mx = max(y_mx, y);
    }

    int d = max(x_mx - x_mn, y_mx - y_mn);
    cout << d * d << '\n';
    return 0;
}
