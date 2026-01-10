// Solve 2026-01-03

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
    int ans = 1;

    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;

        while (n % i == 0) {
            cnt++;
            n /= i;
        }

        ans *= cnt + 1;
    }

    if (n > 1) {
        ans *= 2;
    }

    cout << ans << '\n';
    return 0;
}
