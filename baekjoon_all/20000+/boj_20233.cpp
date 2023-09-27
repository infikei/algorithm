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

    int a, x, b, y, t;
    cin >> a >> x >> b >> y >> t;

    cout << a + max(0, t - 30) * x * 21 << ' ';
    cout << b + max(0, t - 45) * y * 21 << '\n';

    return 0;
}
