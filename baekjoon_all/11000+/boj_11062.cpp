// Solve 2025-11-27

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

int arr[1001];
int prefix[1001];
int memo[1001][1001];

int f(int l, int r) {
    if (l == r) return arr[l];
    if (memo[l][r] != -1) return memo[l][r];

    int v1 = arr[l] + prefix[r] - prefix[l] - f(l + 1, r);
    int v2 = arr[r] + prefix[r - 1] - prefix[l - 1] - f(l, r - 1);
    return memo[l][r] = max(v1, v2);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            prefix[i] = prefix[i - 1] + arr[i];
        }

        memset(memo, -1, sizeof memo);
        cout << f(1, n) << '\n';
    }

    return 0;
}
