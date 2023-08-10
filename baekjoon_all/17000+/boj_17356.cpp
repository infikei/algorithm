// Solve 2022-11-03
// Update 2023-08-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(9);

    int a, b;
    cin >> a >> b;

    double ans = 1 / (1 + pow(10, (double)(b - a) / 400));

    cout << ans << '\n';

    return 0;
}
