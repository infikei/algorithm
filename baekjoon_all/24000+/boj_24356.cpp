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

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int dt = (h2 - h1) * 60 + m2 - m1;

    if (dt < 0) dt += 1440;

    cout << dt << ' ' << dt / 30 << '\n';

    return 0;
}
