// Solve 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int l, w, a;
        cin >> l >> w >> a;

        if (l == 0 && w == 0 && a == 0) break;

        if (l == 0) {
            l = a / w;
        }
        else if (w == 0) {
            w = a / l;
        }
        else if (a == 0) {
            a = w * l;
        }

        cout << l << ' ' << w << ' ' << a << '\n';
    }

    return 0;
}
