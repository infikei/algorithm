// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int m, s, g, l, r;
    double a, b;
    cin >> m >> s >> g >> a >> b >> l >> r;

    double left = (double)m / g + l / a;
    double right = (double)m / s + r / b;

    if (left < right) cout << "friskus\n";
    else cout << "latmask\n";

    return 0;
}
