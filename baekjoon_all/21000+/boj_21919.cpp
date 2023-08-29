// Solve 2022-08-03
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool is_prime(int k) {
    for (int i = 2, ie = sqrt(k); i <= ie; i++) {
        if (k % i == 0) return false;
    }

    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (ans % x != 0 && is_prime(x)) {
            ans *= x;
        }
    }

    if (ans == 1) ans = -1;

    cout << ans << '\n';

    return 0;
}
