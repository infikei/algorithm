// Solve 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int l, r, a;
    cin >> l >> r >> a;

    if (l < r) {
        int x = min(a, r - l);
        l += x;
        a -= x;
    }
    else if (l > r) {
        int x = min(a, l - r);
        r += x;
        a -= x;
    }

    l += a / 2;
    r += a / 2;

    cout << min(l, r) * 2 << '\n';

    return 0;
}
