// Solve 2024-01-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int ans = min({ abs(a - b), abs(a - x) + abs(y - b), abs(a - y) + abs(x - b) });
    cout << ans << '\n';

    return 0;
}
