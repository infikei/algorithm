// Solve 2025-03-10

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

int soldier[100][3];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> soldier[i][0] >> soldier[i][1] >> soldier[i][2];
    }

    int ans = 3000001;

    for (int i = 0; i < n; i++) {
        int x = soldier[i][0];

        for (int ii = 0; ii < n; ii++) {
            int xx = soldier[ii][1];

            for (int iii = 0; iii < n; iii++) {
                int xxx = soldier[iii][2];
                int cnt = 0;

                for (int u = 0; u < n; u++) {
                    if (x >= soldier[u][0] && xx >= soldier[u][1] && xxx >= soldier[u][2]) {
                        cnt++;
                    }
                }

                if (cnt >= k) {
                    ans = min(ans, x + xx + xxx);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
