// Solve 2023-11-24

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
        ll wy, hy, wk, hk;
        cin >> wy >> hy >> wk >> hk;

        ll y = wy * hy;
        ll k = wk * hk;

        if (y < k) cout << "Eurecom\n";
        else if (y > k) cout << "TelecomParisTech\n";
        else cout << "Tie\n";
    }

    return 0;
}
