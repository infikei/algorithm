// Solve 2022-07-03
// Update 2025-11-18

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

int arr[10001];
int memo[10001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    memo[1] = arr[1];
    memo[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        memo[i] = max(memo[i - 1], max(memo[i - 2] + arr[i], memo[i - 3] + arr[i - 1] + arr[i]));
    }

    cout << memo[n] << '\n';
    return 0;
}
