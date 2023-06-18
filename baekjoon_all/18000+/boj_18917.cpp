// Solve 2023-06-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int m;
    cin >> m;

    ll ans = 0;
    int ans2 = 0;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            ans += x;
            ans2 ^= x;
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            ans -= x;
            ans2 ^= x;
        }
        else if (cmd == 3) {
            cout << ans << '\n';
        }
        else {
            cout << ans2 << '\n';
        }
    }

    return 0;
}
