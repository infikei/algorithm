// Solve 2022-06-02
// Update 2023-02-22

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

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    if (a == b && a == c) {
        ans = (a + 10) * 1000;
    }
    else if (a == b || a == c) {
        ans = (a + 10) * 100;
    }
    else if (b == c) {
        ans = (b + 10) * 100;
    }
    else {
        ans = max(a, max(b, c)) * 100;
    }

    cout << ans << '\n';

    return 0;
}