// Solve 2025-03-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int w, h, x, y, x1, y1, x2, y2;
    cin >> w >> h >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (y1 >= y) {
        cout << 0 << '\n';
        return 0;
    }

    double a = (double) (x1 * y - x * y1) / (y - y1);
    double b = (double) (x2 * y - x * y2) / (y - y2);

    a = max((double) 0, min((double) w, a));
    b = max((double) 0, min((double) w, b));

    double ans = (b - a) / w;
    SETP(12);
    cout << ans << '\n';

    return 0;
}
