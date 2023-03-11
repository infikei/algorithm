// Solve 2023-03-10

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

const int MAX_SIZE = 1000000001;

bool is_prime(int k) {
    if (k < 2) {
        return false;
    }

    int i_end = sqrt(k);
    for (int i = 2; i <= i_end; i++) {
        if (k % i == 0) {
            return false;
        }
    }

    return true;
}

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

    while (true) {
        ll p, a;
        cin >> p >> a;
        if (p == 0 && a == 0) {
            break;
        }

        if (!is_prime(p) && calc_power(a, p, p) == a) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}