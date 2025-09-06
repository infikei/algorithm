// Solve 2025-07-27
// Update 2025-09-05

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

ll memo2[1001];
ll memo[1001];

ll count_for_max_height_2(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (memo2[x] != -1) return memo2[x];

    ll& ret = memo2[x];
    ret = count_for_max_height_2(x - 1);
    ret += count_for_max_height_2(x - 2) * 2;
    ret += count_for_max_height_2(x - 3) * 3;
    ret %= MOD;
    return ret;
}

ll count_for_max_height_1(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (memo[x] != -1) return memo[x];

    ll& ret = memo[x];
    ret = count_for_max_height_1(x - 1);
    ret += count_for_max_height_1(x - 2);
    ret += count_for_max_height_1(x - 3);
    ret %= MOD;
    return ret;
}

int main() {
    FASTIO;

    memset(memo2, -1, sizeof memo2);
    memset(memo, -1, sizeof memo);

    int n;
    cin >> n;
    ll ans = (count_for_max_height_2(n) - count_for_max_height_1(n) + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
