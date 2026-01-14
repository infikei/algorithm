// Solve 2026-01-14

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
    vector<pii> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        y = (x == 1 || x == 4) ? -y : y;
        x = x == 2 ? 3 : x == 3 ? 2 : x;
        points.emplace_back(x, y);
    }

    int cnt_cross = 0;
    int mx = 0;

    for (int i = 0; i < n; i += 2) {
        int cur = 0;
        pii a = points[i];
        pii b = points[i + 1];

        if (a > b) swap(a, b);

        for (int j = 0; j < n; j += 2) {
            if (i == j) continue;

            pii c = points[j];
            pii d = points[j + 1];

            if (c > d) swap(c, d);

            if (a < c && d < b) continue;
            if (c < a && b < d) continue;
            if (d < a) continue;
            if (b < c) continue;

            cur++;
        }

        mx = max(mx, cur);
        cnt_cross += cur;
    }

    cnt_cross /= 2;
    cout << cnt_cross << '\n';
    cout << mx << '\n';
    return 0;
}
