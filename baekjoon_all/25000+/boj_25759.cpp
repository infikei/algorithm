// Solve 2025-10-08

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

int n;
int arr[100001];
int memo[100001][101];

int recur(int cur, int prv_val) {
    if (cur > n) {
        return 0;
    }

    if (memo[cur][prv_val] != -1) {
        return memo[cur][prv_val];
    }

    int diff = prv_val == 0 ? 0 : arr[cur] - prv_val;
    int ret1 = recur(cur + 1, arr[cur]) + diff * diff;
    int ret2 = recur(cur + 1, prv_val);
    return memo[cur][prv_val] = max(ret1, ret2);
}

int main() {
    FASTIO;

    memset(memo, -1, sizeof memo);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = recur(1, 0);
    cout << ans << '\n';
    return 0;
}
