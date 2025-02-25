// Solve 2023-12-20
// Update 2025-02-25

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

    for (int ti = 1; ti <= t; ti++) {
        int x, y, z;
        char op, eq;
        cin >> x >> op >> y >> eq >> z;

        bool ans;

        if (op == '+') {
            ans = (x + y == z);
        }
        else {
            ans = (x - y == z);
        }

        cout << "Case " << ti << ": " << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
