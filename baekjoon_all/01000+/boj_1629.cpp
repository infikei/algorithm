// Solve 2022-12-06
// Update 2023-03-08

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

ll calc_power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

int main() {
    FASTIO;

    ll a, b, c;
    cin >> a >> b >> c;

    cout << calc_power(a, b, c) << '\n';

    return 0;
}