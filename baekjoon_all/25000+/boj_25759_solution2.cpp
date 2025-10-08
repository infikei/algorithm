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
int memo[101];

int main() {
    FASTIO;

    fill(memo, memo + 101, -1000000000);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int mx = 0;

        for (int j = 1; j <= 100; j++) {
            mx = max(mx, memo[j] + (arr[i] - j) * (arr[i] - j));
        }

        memo[arr[i]] = mx;
    }

    int ans = 0;

    for (int i = 1; i <= 100; i++) {
        ans = max(ans, memo[i]);
    }

    cout << ans << '\n';
    return 0;
}
