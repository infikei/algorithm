// Solve 2023-03-16
// Update 2024-05-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;
ll x[100000];

inline ll calc_val(ll k) {
    ll res = 0;
    ll cur = 0;

    for (int i = 0; i < n; i++) {
        res += abs(x[i] - cur);
        cur += k;
    }

    return res;
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
        ll mid1 = ((low << 1) + high) / 3;
        ll mid2 = (low + (high << 1)) / 3;

        ll mid1_val = calc_val(mid1);
        ll mid2_val = calc_val(mid2);

        if (mid1_val < mid2_val) {
            high = mid2;
        }
        else {
            low = mid1;
        }
    }

    ll ans = 1e18;

    for (int k = low; k <= high; k++) {
        ans = min(ans, calc_val(k));
    }

    cout << ans << '\n';

    return 0;
}
