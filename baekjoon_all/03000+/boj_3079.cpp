// Solve 2023-05-06
// Update 2023-08-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll t[100000];

int main() {
    FASTIO;

    int n;
    ll m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    ll low = 0, high = 1e18;

    while (low + 1 < high) {
        ll mid = (low + high) >> 1;
        ll val = 0;

        for (int i = 0; i < n; i++) {
            val += mid / t[i];
            if (val >= m) break;
        }

        if (val >= m) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    cout << high << '\n';

    return 0;
}
