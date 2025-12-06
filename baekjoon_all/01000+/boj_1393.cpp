// Solve 2025-12-04

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

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int get_dist_square(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int a, b, x, y, dx, dy;
    cin >> a >> b >> x >> y >> dx >> dy;

    int g = get_gcd(abs(dx), abs(dy));

    if (g != 0) {
        dx /= g;
        dy /= g;
    }

    int prv_d = get_dist_square(x, y, a, b);
    int prv_x = x;
    int prv_y = y;

    while (true) {
        x += dx;
        y += dy;
        int nxt_d = get_dist_square(x, y, a, b);

        if (prv_d < nxt_d) {
            cout << prv_x << ' ' << prv_y << '\n';
            return 0;
        }

        prv_d = nxt_d;
        prv_x = x;
        prv_y = y;
    }

    return 0;
}
