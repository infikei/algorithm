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

int d[1000];
int m[1000];
int memo[1001];

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= t; i++) {
        memo[i] = -INF;
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[i] >> m[i];
        s += m[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = t; j >= d[i]; j--) {
            memo[j] = max(memo[j], memo[j - d[i]] + m[i]);
        }
    }

    int mx = 0;

    for (int i = 0; i <= t; i++) {
        mx = max(mx, memo[i]);
    }

    cout << s - mx << '\n';
    return 0;
}
