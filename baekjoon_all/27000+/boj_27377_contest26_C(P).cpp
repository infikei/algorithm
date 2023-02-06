#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

ll n, s, t, k;

ll calc(ll m) {
    if (m <= k * 2) {
        return m * s;
    }
    if (m % 2 == 1) {
        return calc(m - 1) + s;
    }
    return calc(m / 2) + t;
}

int main() {
    FASTIO;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        cin >> n >> s >> t;
        k = t / s;
        cout << calc(n) << '\n';
    }

    return 0;
}