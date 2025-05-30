// Solve 2023-07-09
// Update 2025-05-27

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int a = 3, s = 4;

    for (int i = 1; i < (n >> 1); i++) {
        a += s << 1; // a_n = a_(n-1) + 2 * S_(n-1)
        s += a; // S_n = S_(n-1) + a_n
    }

    cout << a << '\n';
    return 0;
}
