// Solve 2023-03-08
// Update 2025-07-27

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

    int n;
    cin >> n;
    int ans = 0;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i != 0) continue;

        int j = n / i;

        if ((i + j) % 2 != 0) continue;

        int a = (j + i) / 2;
        int b = (j - i) / 2;

        if (a > 500 || b < 1) continue;

        ans++;
    }

    cout << ans << '\n';
    return 0;
}
