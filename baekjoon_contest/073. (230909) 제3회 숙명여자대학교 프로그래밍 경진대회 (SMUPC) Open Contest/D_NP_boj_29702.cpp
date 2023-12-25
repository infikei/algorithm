// Solve 2023-09-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        ll n;
        cin >> n;

        ll n_copy = n;
        int cnt = 0;

        while (n_copy > 1) {
            n_copy >>= 1;
            cnt++;
        }

        ll r = n - (1ll << cnt) + 1;
        cnt++;

        while (cnt >= 1) {
            cout << cnt << setfill('0') << setw(18) << r << '\n';
            cnt--;
            r++;
            r >>= 1;
        }
    }

    return 0;
}
