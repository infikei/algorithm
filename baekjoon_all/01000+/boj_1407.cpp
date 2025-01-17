// Solve 2025-01-16

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

ll f(ll x) {
    ll b = 1;
    ll res = 0;

    while (b <= x) {
        ll cnt = x / b - x / (b << 1);
        res += cnt * b;
        b <<= 1;
    }

    return res;
}

int main() {
    FASTIO;

    ll a, b;
    cin >> a >> b;

    println(f(b) - f(a - 1));

    return 0;
}
