// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k, c, r;
    cin >> n >> k >> c >> r;

    vector<int> base(k + 1, 0), s(k + 1, 0), p(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        cin >> base[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }

    ll stardust = 0;
    int combo = 0, fatigue = 0;
    vector<int> skill(k + 1, 0);

    for (int ni = 1; ni <= n; ni++) {
        int l;
        cin >> l;

        if (stardust == -1) continue;

        if (l == 0) {
            combo = 0;
            fatigue -= r;

            if (fatigue < 0) {
                fatigue = 0;
            }
        }
        else {
            stardust += (ll)(100 + combo * c) * (100 + skill[l] * s[l]) * base[l] / 10000;
            combo++;
            skill[l]++;
            fatigue += p[l];

            if (fatigue > 100) {
                stardust = -1;
            }
        }
    }

    cout << stardust << '\n';

    return 0;
}
