// Solve 2025-09-07

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

int memo[2001];

int main() {
    FASTIO;

    memset(memo, -1, sizeof memo);
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;

        if (memo[x] == -1) {
            memo[x] = i;
        }
        else {
            ans = max(ans, i - memo[x] - 1);
        }
    }

    cout << ans << '\n';
    return 0;
}
