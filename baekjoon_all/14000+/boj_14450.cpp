// Solve 2025-12-08

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

int memo[21][3];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int d = (c == 'H' ? 0 : c == 'P' ? 1 : 2);

        for (int j = k; j >= 1; j--) {
            int mx = *max_element(memo[j - 1], memo[j - 1] + 3);
            memo[j][0] = max(memo[j][0], mx);
            memo[j][1] = max(memo[j][1], mx);
            memo[j][2] = max(memo[j][2], mx);
            memo[j][d]++;
        }

        memo[0][d]++;
    }

    int mx = 0;

    for (int i = 0; i <= k; i++) {
        mx = max(mx, *max_element(memo[i], memo[i] + 3));
    }

    cout << mx << '\n';
    return 0;
}
