// Solve 2022-06-30
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;

    int x_cost = a * p;
    int y_cost = b + max(0, p - c) * d;

    cout << min(x_cost, y_cost) << '\n';

    return 0;
}
