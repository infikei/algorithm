// Solve 2023-02-23

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int a2, a1, a0, c1, c2, n0;
    cin >> a2 >> a1 >> a0 >> c1 >> c2 >> n0;

    int ans = 0;

    // 백준 24368번
    if (a2 == c2) {
        if (a1 * n0 + a0 <= 0 && a1 <= 0) {
            ans++;
        }
    }
    else {
        if (a2 < c2 && (a2 - c2) * n0 * n0 + a1 * n0 + a0 <= 0 && ((a2 - c2) * n0 * 2 + a1 <= 0 || a1 * a1 <= a0 * (a2 - c2) * 4)) {
            ans++;
        }
    }

    // 백준 24369번
    if (a2 == c1) {
        if (a1 * n0 + a0 >= 0 && a1 >= 0) {
            ans++;
        }
    }
    else {
        if (a2 > c1 && (a2 - c1) * n0 * n0 + a1 * n0 + a0 >= 0 && ((a2 - c1) * n0 * 2 + a1 >= 0 || a1 * a1 <= a0 * (a2 - c1) * 4)) {
            ans++;
        }
    }

    // ans = 2일 때 1 출력
    // ans = 0, 1일 때 0 출력
    ans >>= 1;
    cout << ans << '\n';

    return 0;
}