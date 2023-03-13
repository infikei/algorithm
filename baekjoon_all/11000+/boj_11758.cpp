// Solve 2022-07-13
// Update 2023-03-13

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pll = pair<ll, ll>;

inline ll ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

int main() {
    FASTIO;

    pll p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i].first >> p[i].second;
    }

    ll ans = ccw(p[0], p[1], p[2]);
    if (ans > 0) {
        cout << 1 << '\n';
    }
    else if (ans < 0) {
        cout << -1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
