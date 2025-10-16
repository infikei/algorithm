// Solve 2025-10-14

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

int spin[100];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        int x = 0;
        int y = 0;

        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            x = x * 10 + v;
        }

        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            y = y * 10 + v;
        }

        for (int i = 0; i < n; i++) {
            cin >> spin[i];
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int z = 0;

            for (int j = 0, u = i; j < m; j++, u = (u + 1) % n) {
                z = z * 10 + spin[u];
            }

            if (x <= z && z <= y) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
