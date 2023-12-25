// Solve 2023-10-07
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    ll p;
    cin >> n >> m >> p;

    bool ans = true;

    for (int i = 0; i < n; i++) {
        vector<ll> enemies;
        int items = 0;

        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;

            if (x == -1) items++;
            else enemies.push_back(x);
        }

        if (ans) {
            sort(enemies.begin(), enemies.end());

            for (ll &e : enemies) {
                while (p < e && items > 0) {
                    p *= 2;
                    items--;
                }

                if (p < e) {
                    ans = false;
                    break;
                }

                p += e;
            }

            while (items > 0) {
                p *= 2;
                items--;
            }
        }
    }

    cout << (ans ? 1 : 0) << '\n';

    return 0;
}
