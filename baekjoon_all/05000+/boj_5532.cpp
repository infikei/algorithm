// Solve 2022-06-18
// Update 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    a = (a - 1) / c + 1;
    b = (b - 1) / d + 1;

    cout << l - max(a, b) << '\n';

    return 0;
}
