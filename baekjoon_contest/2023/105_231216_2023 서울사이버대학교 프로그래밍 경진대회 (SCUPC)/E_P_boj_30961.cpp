// Solve 2023-12-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<ll> a(n);

    for (ll &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    ll ans = a[0] * a[0];

    for (int i = 1; i < n; i++) {
        ans ^= a[i] * a[i - 1];
        ans ^= a[i] * a[i];
    }

    cout << ans << '\n';

    return 0;
}
