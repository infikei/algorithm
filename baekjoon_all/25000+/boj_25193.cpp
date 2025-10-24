// Solve 2025-10-24

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
    int chicken = 0;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'C') chicken++;
    }

    int other = n - chicken;
    // int ans = ceil(chicken / (other + 1));
    // int ans = (chicken + other) / (other + 1);
    int ans = n / (other + 1);
    cout << ans << '\n';
    return 0;
}
