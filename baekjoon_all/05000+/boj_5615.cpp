// Solve 2025-01-23

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

ull mod_pow(ull a, ull p, ull mod) {
    a %= mod;
    ull res = 1;

    while (p > 0) {
        if (p & 1) {
            res = res * a % mod;
        }

        a = a * a % mod;
        p >>= 1;
    }

    return res;
}

bool is_probable_prime_with_miller_rabin(ull n, ull a) {
    ull d = n - 1;
    int s = 0;

    while (d % 2 == 0) {
        d >>= 1;
        s++;
    }

    ull a_pow = mod_pow(a, d, n);

    if (a_pow == 1 || a_pow == n - 1) return true;

    for (int r = 1; r < s; r++) {
        a_pow = a_pow * a_pow % n;

        if (a_pow == n - 1) {
            return true;
        }
    }

    return false;
}

bool is_prime_with_miller_rabin(ull n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    ull a_list[3] = { 2, 7, 61 };

    for (ull a : a_list) {
        if (a >= n - 1) return true;
        if (n % a == 0) return false;

        if (!is_probable_prime_with_miller_rabin(n, a)) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int impossible_cnt = 0;

    while (n-- > 0) {
        uint area;
        cin >> area;

        if (is_prime_with_miller_rabin(area * 2 + 1)) {
            impossible_cnt++;
        }
    }

    println(impossible_cnt);

    return 0;
}
