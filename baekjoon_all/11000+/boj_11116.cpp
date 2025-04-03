// Solve 2025-04-03

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

    while (t-- > 0) {
        int m;
        cin >> m;

        map<int, int> hs;

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            hs[x] = 1;
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            hs[x] = 2;
        }

        int ans = 0;

        for (auto it = hs.begin(); it != hs.end(); it++) {
            int x = it->first;

            if (it->second == 1 && hs[x + 500] == 1 && hs[x + 1000] == 2 && hs[x + 1500] == 2) {
                ans++;
                it->second = 0;
                hs[x + 500] = 0;
                hs[x + 1000] = 0;
                hs[x + 1500] = 0;
            }
            else if (it->second == 2 && hs[x + 500] == 2 && hs[x + 1000] == 1 && hs[x + 1500] == 1) {
                it->second = 0;
                hs[x + 500] = 0;
                hs[x + 1000] = 0;
                hs[x + 1500] = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
