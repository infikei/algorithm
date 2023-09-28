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

    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    int ans = (max(w1, w2) + h1 + h2 + 2) * 2;

    cout << ans << '\n';

    return 0;
}
