// Solve 2025-04-04

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

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, s, p, x, y;
        cin >> n >> s >> p >> x >> y;

        int dist_sum = 0;

        for (int i = 0; i < n; i++) {
            int nx, ny;
            cin >> nx >> ny;

            dist_sum += abs(x - nx) + abs(y - ny);
            x = nx;
            y = ny;
        }

        int ans = (dist_sum * s - 1) / p + 1;

        if (ti >= 2) cout << '\n';
        cout << "Data Set " << ti << ":" << '\n';
        cout << ans << '\n';
    }

    return 0;
}
