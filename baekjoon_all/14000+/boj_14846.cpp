// Solve 2026-01-03

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

int prefix[11][301][301];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int i = 1; i <= 10; i++) {
                prefix[i][x][y] = prefix[i][x][y - 1] + prefix[i][x - 1][y] - prefix[i][x - 1][y - 1];
            }

            int v;
            cin >> v;
            prefix[v][x][y]++;
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;

        int cnt = 0;

        for (int i = 1; i <= 10; i++) {
            if (prefix[i][x2][y2] - prefix[i][x2][y1] - prefix[i][x1][y2] + prefix[i][x1][y1] >= 1) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
