// Solve 2022-09-05
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = 3.141592;

int main() {
    FASTIO;

    int d1, d2;
    cin >> d1 >> d2;

    SETPRECISION(8);

    cout << 2 * (d1 + d2 * PI) << '\n';

    return 0;
}
