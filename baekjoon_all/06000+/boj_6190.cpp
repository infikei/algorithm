// Solve 2023-10-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    int ans = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }

        ans++;
    }

    cout << ans << '\n';

    return 0;
}
