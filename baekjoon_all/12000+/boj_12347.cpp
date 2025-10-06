// Solve 2025-10-05

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

    ll n;
    cin >> n;
    vector<ll> hansu;

    for (int d = 1; d <= 9; d++) {
        hansu.push_back(d);

        for (int dd = -9; dd <= 9; dd++) {
            ll x = d;
            int iter = 17;

            while (iter-- > 0) {
                ll nd = x % 10 + dd;

                if (nd < 0 || nd >= 10) break;

                x = x * 10 + nd;
                hansu.push_back(x);
            }
        }
    }

    sort(hansu.begin(), hansu.end());
    UNIQUE(hansu);
    int idx = upper_bound(hansu.begin(), hansu.end(), n) - hansu.begin();
    cout << idx << '\n';
    return 0;
}
