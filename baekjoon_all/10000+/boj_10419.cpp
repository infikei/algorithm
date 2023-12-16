// Solve 2022-11-24
// Update 2023-12-16

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

    for (int ti = 0; ti < t; ti++) {
        int d;
        cin >> d;

        int ans = 1;

        while (ans * (ans + 1) <= d) {
            ans++;
        }

        ans--;

        cout << ans << '\n';
    }

    return 0;
}
