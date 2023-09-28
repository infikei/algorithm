// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s, a, b;
    cin >> s >> a >> b;

    int ans = 250;

    if (s > a) ans += ((s - a - 1) / b + 1) * 100;

    cout << ans << '\n';

    return 0;
}
