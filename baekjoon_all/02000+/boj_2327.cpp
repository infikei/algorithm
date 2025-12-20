// Solve 2025-12-20

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

int memo[100001];

int main() {
    FASTIO;

    int hh, n;
    cin >> hh >> n;

    memo[0] = INF;

    for (int i = 1; i <= hh; i++) {
        memo[i] = -INF;
    }

    for (int i = 0; i < n; i++) {
        int h, s;
        cin >> h >> s;

        for (int i = hh; i >= h; i--) {
            memo[i] = max(memo[i], min(memo[i - h], s));
        }
    }

    cout << (memo[hh] == -INF ? -1 : memo[hh]) << '\n';
    return 0;
}
