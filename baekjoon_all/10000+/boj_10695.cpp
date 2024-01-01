// Solve 2023-12-30

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
        int n, r1, c1, r2, c2;
        cin >> n >> r1 >> c1 >> r2 >> c2;

        bool ans;

        if (abs(r1 - r2) == 1 && abs(c1 - c2) == 2) {
            ans = true;
        }
        else if (abs(r1 - r2) == 2 && abs(c1 - c2) == 1) {
            ans = true;
        }
        else {
            ans = false;
        }

        cout << "Case " << ti << ": " << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
