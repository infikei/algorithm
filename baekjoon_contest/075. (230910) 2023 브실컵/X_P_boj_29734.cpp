// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n, m, t, s;
    cin >> n >> m >> t >> s;

    ll zip = n + (n - 1) / 8 * s;
    ll dok = m + (m - 1) / 8 * (t + t + s) + t;

    if (zip < dok) {
        cout << "Zip\n" << zip << '\n';
    }
    else {
        cout << "Dok\n" << dok << '\n';
    }

    return 0;
}
