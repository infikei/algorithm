// Solve 2025-09-23

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

int get_dist(int x1, int y1, int x2, int y2) {
    if ((x1 < x2 && y1 < y2) || (x1 > x2 && y1 > y2)) {
        return max(abs(x1 - x2), abs(y1 - y2));
    }

    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    FASTIO;

    int w, h, n;
    cin >> w >> h >> n;

    int x1, y1;
    cin >> x1 >> y1;
    int dist_sum = 0;

    for (int i = 1; i < n; i++) {
        int x2, y2;
        cin >> x2 >> y2;
        dist_sum += get_dist(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }

    cout << dist_sum << '\n';
    return 0;
}
