// Solve 2023-07-29
// Update 2025-09-20

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

int cloud[301][301];

int get_area(int x1, int y1, int x2, int y2) {
    return cloud[x2][y2] - cloud[x2][y1 - 1] + cloud[x1 - 1][y1 - 1] - cloud[x1 - 1][y2];
}

int main() {
    FASTIO;

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            int val;
            cin >> val;
            cloud[x][y] = cloud[x - 1][y] - cloud[x - 1][y - 1] + cloud[x][y - 1] + val;
        }
    }

    int ans = INF;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            // 1번째 모양
            int x_end = x + a;
            int y_end = y + b + c;

            if (x_end - 1 <= n && y_end - 1 <= m) {
                ans = min(ans, get_area(x, y, x_end - 1, y_end - 1));
            }

            // 2번째 모양
            int x_mid = x + a;
            int y_mid = y + c;
            x_end = x + a + b;
            y_end = y + a + c;

            if (x_end - 1 <= n && y_end - 1 <= m) {
                ans = min(ans, get_area(x, y, x_mid - 1, y_mid - 1) + get_area(x_mid, y_mid, x_end - 1, y_end - 1));
            }

            // 3번째 모양
            x_mid = x + a;
            y_mid = y + b;
            x_end = x + a + c;
            y_end = y + a + b;

            if (x_end - 1 <= n && y_end - 1 <= m) {
                ans = min(ans, get_area(x, y, x_mid - 1, y_mid - 1) + get_area(x_mid, y_mid, x_end - 1, y_end - 1));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
