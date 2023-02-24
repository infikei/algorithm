// Solve 2022-06-03
// Update 2023-02-24

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

    int cnt[42] = { 0 };
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        cnt[x % 42]++;
    }

    int ans = 0;
    for (int a : cnt) {
        if (a > 0) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}