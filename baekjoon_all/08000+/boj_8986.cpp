// Solve 2023-03-16
// Update 2025-12-07

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
ll x[100000];

ll get_val(ll gap) {
    ll ret = 0;

    for (int i = 0; i < n; i++) {
        ret += abs(x[i] - i * gap);
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll low = 1;
    ll high = 1e9;

    while (low + 2 < high) {
        ll mid1 = (low * 2 + high) / 3;
        ll mid2 = (low + high * 2) / 3;

        ll mid1_val = get_val(mid1);
        ll mid2_val = get_val(mid2);

        if (mid1_val < mid2_val) {
            high = mid2;
        }
        else {
            low = mid1;
        }
    }

    ll mn = 1e18;

    for (int i = low; i <= high; i++) {
        mn = min(mn, get_val(i));
    }

    cout << mn << '\n';
    return 0;
}
