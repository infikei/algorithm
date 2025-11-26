// Solve 2025-11-24

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

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int x_low = 1;
    int x_high = n;
    int y_low = 1;
    int y_high = n;

    while (m-- > 0) {
        int x, y, k;
        cin >> x >> y >> k;

        if (dx[k] == -1) {
            x_high = min(x_high, x - 1);
        }
        else if (dx[k] == 1) {
            x_low = max(x_low, x + 1);
        }
        else {
            x_low = x;
            x_high = x;
        }

        if (dy[k] == -1) {
            y_high = min(y_high, y - 1);
        }
        else if (dy[k] == 1) {
            y_low = max(y_low, y + 1);
        }
        else {
            y_low = y;
            y_high = y;
        }
    }

    cout << x_low << ' ' << y_low << '\n';
    return 0;
}
