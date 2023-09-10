// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s0, n, m;
    cin >> s0 >> n >> m;

    int s = s0, u = 0;

    for (int i = 0, ie = n + m; i < ie; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            if (++u > s) s *= 2;
        }
        else {
            u--;
        }
    }

    cout << s << '\n';

    return 0;
}
