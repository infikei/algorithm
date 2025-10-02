// Solve 2025-10-01

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

    int m;
    string s;
    cin >> m >> s;
    int n = (int) size(s) / m;

    string ans;

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (x % 2 == 0) {
                ans.push_back(s[x * m + y]);
            }
            else {
                ans.push_back(s[x * m + (m - 1 - y)]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
