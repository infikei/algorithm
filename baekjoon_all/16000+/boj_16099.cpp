// Solve 2023-11-24
// Update 2025-03-09

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

    int t;
    cin >> t;

    while (t-- > 0) {
        ll wy, hy, wk, hk;
        cin >> wy >> hy >> wk >> hk;

        ll y = wy * hy;
        ll k = wk * hk;

        if (y < k) cout << "Eurecom" << '\n';
        else if (y > k) cout << "TelecomParisTech" << '\n';
        else cout << "Tie" << '\n';
    }

    return 0;
}
