// Solve 2023-11-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> water(n + 1, 0);
    vector<bool> toggle(n + 1, true);
    ll cur_water = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        water[i] = x;
        cur_water += x;
    }

    cout << cur_water << '\n';

    int q;
    cin >> q;

    for (int qi = 0; qi < q; qi++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, x;
            cin >> i >> x;

            if (toggle[i]) {
                cur_water -= water[i];
                cur_water += x;
            }

            water[i] = x;
        }
        else {
            int i;
            cin >> i;

            if (toggle[i]) {
                cur_water -= water[i];
                toggle[i] = false;
            }
            else {
                cur_water += water[i];
                toggle[i] = true;
            }
        }

        cout << cur_water << '\n';
    }

    return 0;
}
