// Solve 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, p;
    cin >> n >> p;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int xp = x;

        for (int j = 1; j < p; j++) {
            xp *= x;
        }

        if (xp > 0) {
            ans += xp;
        }
    }

    cout << ans << '\n';

    return 0;
}
