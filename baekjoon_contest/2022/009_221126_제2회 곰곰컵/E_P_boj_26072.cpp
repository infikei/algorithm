// Solve 2022-11-26
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

int x[100000];

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll w_sum = 0;
    ll prod_sum = 0;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;

        w_sum += w;
        prod_sum += (ll) w * x[i];
    }

    double ans = prod_sum / (double) w_sum;
    SETP(9);
    cout << ans << '\n';
    return 0;
}
