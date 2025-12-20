// Solve 2025-12-16

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
int arr[2001];
int memo[2001][2001];

int recur(int a, int b) {
    int cur = a + 1;

    if (cur > n) return 0;
    if (memo[a][b] != -1) return memo[a][b];

    int x = recur(cur, b);

    if (a != 0) x += abs(arr[cur] - arr[a]);

    int y = recur(cur, a);

    if (b != 0) y += abs(arr[cur] - arr[b]);

    return memo[a][b] = min(x, y);
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    memset(memo, -1, sizeof memo);
    cout << recur(0, 0) << '\n';
    return 0;
}
