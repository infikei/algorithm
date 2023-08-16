// Solve 2023-08-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(2);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string h_oh;
        char c;
        double d, ans;

        cin >> h_oh >> c >> d;

        if (h_oh == "H") ans = -log10(d);
        else ans = 14 + log10(d);

        cout << ans << '\n';
    }

    return 0;
}
