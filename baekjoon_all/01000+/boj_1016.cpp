// Solve 2022-09-10
// Update 2023-06-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool check[1000002];

int main() {
    FASTIO;

    ll n_min, n_max;
    cin >> n_min >> n_max;

    int cnt = n_max - n_min + 1;
    ll a = 2, a2 = 4;

    while (a2 <= n_max) {
        ll n = n_min / a2 * a2;
        if (n < n_min) n += a2;

        while (n <= n_max) {
            if (!check[n - n_min]) {
                check[n - n_min] = true;
                cnt--;
            }
            n += a2;
        }

        a++;
        a2 = a * a;
    }

    cout << cnt << '\n';

    return 0;
}
