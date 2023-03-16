// Solve 2022-09-05
// Update 2023-03-16

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

inline int ccw(pll p0, pll p1, pll p2) {
    ll res = (p1.first - p0.first) * (p2.second - p0.second) - (p2.first - p0.first) * (p1.second - p0.second);

    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}

int main() {
    FASTIO;

    pll pt[4];
    for (int i = 0; i < 4; i++) {
        cin >> pt[i].first >> pt[i].second;
    }

    if (ccw(pt[0], pt[1], pt[2]) + ccw(pt[0], pt[1], pt[3]) == 0 && ccw(pt[2], pt[3], pt[0]) + ccw(pt[2], pt[3], pt[1]) == 0) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
