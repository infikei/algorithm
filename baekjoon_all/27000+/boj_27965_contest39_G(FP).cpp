// Solve 2023-04-18

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

int main() {
    FASTIO;

    ll n, k;
    cin >> n >> k;

    ll val = 0;
    ll p = 10, p2 = 10;
    for (int i = 1; i <= n; i++) {
        if (i >= p) {
            p *= 10;
            p2 = p % k;
        }
        val *= p2;
        val += i;
        val %= k;
    }
    cout << val << '\n';

    return 0;
}
