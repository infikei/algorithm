// Solve 2026-06-27

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

int arr[301];
int memo[301][2];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    memo[1][0] = arr[1];

    for (int i = 2; i <= n; i++) {
        memo[i][0] = max(memo[i - 2][0], memo[i - 2][1]) + arr[i];
        memo[i][1] = memo[i - 1][0] + arr[i];
    }

    cout << max(memo[n][0], memo[n][1]) << '\n';
    return 0;
}
