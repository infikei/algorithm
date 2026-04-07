// Solve 2026-04-04

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

    int r, g, b;
    cin >> r >> g >> b;

    if (r == 0 && g == 0 && b == 0) {
        cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << 1 << '\n';
        return 0;
    }

    double rr = (double) r / 255;
    double gg = (double) g / 255;
    double bb = (double) b / 255;

    double k = 1 - max(rr, max(gg, bb));
    double c = (1 - rr - k) / (1 - k);
    double m = (1 - gg - k) / (1 - k);
    double y = (1 - bb - k) / (1 - k);

    SETP(9);
    cout << c << ' ' << m << ' ' << y << ' ' << k << '\n';
    return 0;
}
