// Solve 2024-01-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;
    SETPRECISION(1);

    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    int aa = d1 + d2 - d3;
    int bb = d1 + d3 - d2;
    int cc = d2 + d3 - d1;

    if (aa <= 0 || bb <= 0 || cc <= 0) {
        cout << -1 << '\n';
    }
    else {
        cout << 1 << '\n';
        cout << aa * 0.5 << ' ' << bb * 0.5 << ' ' << cc * 0.5 << '\n';
    }

    return 0;
}
