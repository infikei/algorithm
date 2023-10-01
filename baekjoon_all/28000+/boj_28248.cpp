// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int p, c;
    cin >> p >> c;

    int ans = p * 50 - c * 10;

    if (p > c) ans += 500;

    cout << ans << '\n';

    return 0;
}
