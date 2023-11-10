// Solve 2023-11-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int ans = ((h - 1) / (n + 1) + 1) * ((w - 1) / (m + 1) + 1);

    cout << ans << '\n';

    return 0;
}
