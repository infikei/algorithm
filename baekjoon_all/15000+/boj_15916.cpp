// Solve 2022-09-23
// Update 2023-11-22

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

    int f[100001];

    for (int x = 1; x <= n; x++) {
        cin >> f[x];
    }

    ll k;
    cin >> k;

    bool is_f1_below_k = false;

    if (f[1] < k) {
        is_f1_below_k = true;
    }

    bool intersects = false;

    for (int x = 1; x <= n; x++) {
        ll kx = k * x;

        if (f[x] == kx) {
            intersects = true;
            break;
        }

        bool is_fx_below_kx = (f[x] < kx);

        if (is_f1_below_k != is_fx_below_kx) {
            intersects = true;
            break;
        }
    }

    if (intersects) cout << "T\n";
    else cout << "F\n";

    return 0;
}
