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

int a[300][300];
int b[300][300];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> a[x][y];
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> b[x][y];
        }
    }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int v = 0;

            for (int i = 0; i < n; i++) {
                if (a[x][i] & b[i][y]) {
                    v = 1;
                    break;
                }
            }

            ans += v;
        }
    }

    cout << ans << '\n';
    return 0;
}
