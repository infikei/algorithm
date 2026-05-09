// Solve 2026-05-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int get_gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int get_lcm(int a, int b) {
    return a / get_gcd(a, b) * b;
}

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    int gcd = d;
    int lcm = d;

    for (int i = 1; i < n; i++) {
        cin >> d;
        gcd = get_gcd(gcd, d);
        lcm = get_lcm(lcm, d);
    }

    cout << gcd << ' ' << lcm << '\n';
    return 0;
}
