// Solve 2025-12-03

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

int memo[101][101];

int f(int n, int k) {
    if (n <= 0 && k == 0) return 1;
    if (n <= k) return 0;
    if (memo[n][k] != -1) return memo[n][k];

    int ret = 0;
    ret += f(n - 1, k);
    ret += f(n - 2, k);

    for (int i = 1; i <= k; i++) {
        ret += f(n - 2 - i, k - i);
    }

    return memo[n][k] = ret;
}

void solution() {
    int n, k;
    cin >> n >> k;
    cout << f(n, k) << '\n';
}

int main() {
    FASTIO;
    memset(memo, -1, sizeof memo);

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
