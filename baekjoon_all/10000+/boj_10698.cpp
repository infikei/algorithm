// Solve 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

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
