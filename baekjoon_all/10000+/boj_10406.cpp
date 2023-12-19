// Solve 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int w, n, p;
    cin >> w >> n >> p;

    int ans = 0;

    for (int i = 0; i < p; i++) {
        int h;
        cin >> h;

        if (w <= h && h <= n) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
