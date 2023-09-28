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

    int g, p, t;
    cin >> g >> p >> t;

    int val = g * p;
    int val2 = g + t * p;

    if (val < val2) cout << 1 << '\n';
    else if (val > val2) cout << 2 << '\n';
    else cout << 0 << '\n';

    return 0;
}
