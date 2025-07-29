// Solve 2025-07-29

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

int p_sum[334][334];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        string row;
        cin >> row;

        for (int y = 1; y <= m; y++) {
            int v = (row[y - 1] == '0' ? 1 : 0);
            p_sum[x][y] = v + p_sum[x][y - 1];
        }
    }

    int max_area = 0;

    for (int y1 = 0; y1 < m; y1++) {
        for (int y2 = y1 + 1; y2 <= m; y2++) {
            int dy = y2 - y1;
            int area = 0;

            for (int x = 1; x <= n; x++) {
                if (p_sum[x][y2] - p_sum[x][y1] == dy) {
                    area += dy;
                    max_area = max(max_area, area);
                }
                else {
                    area = 0;
                }
            }
        }
    }

    cout << max_area << '\n';
    return 0;
}
