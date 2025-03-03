// Solve 2022-09-15
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int a, b;
        cin >> a >> b;

        int gcd = get_gcd(a, b);
        int lcm = a / gcd * b;
        cout << lcm << ' ' << gcd << '\n';
    }

    return 0;
}
