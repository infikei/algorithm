// Solve 2024-01-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h, m, s, q;
    cin >> h >> m >> s >> q;

    int cur = h * 3600 + m * 60 + s;

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int dt;
            cin >> dt;

            cur += dt;
            cur %= 86400;
        }
        else if (cmd == 2) {
            int dt;
            cin >> dt;

            cur -= dt;

            while (cur < 0) {
                cur += 86400;
            }
        }
        else {
            cout << cur / 3600 << ' ' << cur % 3600 / 60 << ' ' << cur % 60 << '\n';
        }
    }

    return 0;
}
