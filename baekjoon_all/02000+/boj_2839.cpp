// Solve 2024-02-13
// Update 2025-07-26

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

int main() {
    FASTIO;

    int memo[15] = {0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4};
    int n;
    cin >> n;
    cout << ((n == 4 || n == 7) ? -1 : (n / 15 * 3 + memo[n % 15])) << '\n';
    return 0;
}
