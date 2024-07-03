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

    for (int ti = 0; ti < t; ti++) {
        int n, m, k;
        cin >> n >> m >> k;

        if (n > 1 && m == 1 && k == 1) {
            cout << -1 << '\n';
            continue;
        }

        int a = n;
        int ans = 0;

        while (true) {
            a -= min(a, k * m);
            ans++;

            if (a == 0) {
                break;
            }
            else {
                a++;
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
