// Solve 2022-12-06
// Update 2023-03-06

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

const ll MOD = 1000000007;
unordered_map<ll, ll> hs;

ll calc_fibonacci(ll k) {
    if (k < 3) {
        return 1;
    }

    ll k2 = k >> 1;
    ll a;
    if (hs.find(k2) == hs.end()) {
        a = calc_fibonacci(k2);
    }
    else {
        a = hs[k2];
    }

    if (k & 1) {
        ll b;
        if (hs.find(k2 + 1) == hs.end()) {
            b = calc_fibonacci(k2 + 1);
        }
        else {
            b = hs[k2 + 1];
        }

        hs[k] = (a * a + b * b) % MOD;
        return hs[k];
    }
    else {
        ll b;
        if (hs.find(k2 - 1) == hs.end()) {
            b = calc_fibonacci(k2 - 1);
        }
        else {
            b = hs[k2 - 1];
        }

        hs[k] = (a + (b << 1)) * a % MOD;
        return hs[k];
    }
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    cout << calc_fibonacci(n) << '\n';

    return 0;
}