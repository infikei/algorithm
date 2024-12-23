// Solve 2024-12-23

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

int main() {
    FASTIO;

    int period;
    cin >> period;

    vector<ll> integrals(period);

    for (ll &i : integrals) {
        cin >> i;
    }

    for (int i = 1; i < period; i++) {
        integrals[i] += integrals[i - 1];
    }

    int a, b;
    cin >> a >> b;

    if (a < 0) {
        int diff = (-a - 1) / period * period + period * 2;
        a += diff;
        b += diff;
    }

    ll from_0_to_b = (b - 1) / period * integrals[period - 1] + integrals[(b - 1) % period];
    ll from_0_to_a = (a - 1) / period * integrals[period - 1] + integrals[(a - 1) % period];

    println(from_0_to_b - from_0_to_a);

    return 0;
}
