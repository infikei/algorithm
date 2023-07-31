// Solve 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int f[3], g[2];
    for (int i = 0; i < 3; i++) cin >> f[i];
    for (int i = 0; i < 2; i++) cin >> g[i];

    int p[3];
    p[0] = f[0] * g[0] * (g[0] - 1);
    p[1] = 2 * f[0] * g[0] * g[1];
    p[2] = f[0] * g[1] * g[1] + f[1] * g[1] + f[2] - f[2] * g[0] - g[1];

    int ans = 0;

    if (p[0] == 0) {
        if (p[1] == 0) {
            if (p[2] == 0) {
                ans = 3;
            }
            else {
                ans = 0;
            }
        }
        else {
            ans = 1;
        }
    }
    else {
        int d = p[1] * p[1] - 4 * p[0] * p[2];

        if (d > 0) ans = 2;
        else if (d < 0) ans = 0;
        else ans = 1;
    }

    string s[4] = {
        "Head on",
        "Remember my character",
        "Go ahead",
        "Nice"
    };

    cout << s[ans] << '\n';

    return 0;
}
