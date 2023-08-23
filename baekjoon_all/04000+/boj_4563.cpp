// Solve 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        ll a;
        cin >> a;
        if (a == 0) break;

        ll a2 = a * a;

        int cnt = 0;

        for (ll i = 1; i < a; i++) {
            ll j = a2 / i;
            if (i * j != a2) continue;

            ll b = (j - i) / 2;

            if (b > a && i % 2 == j % 2) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
