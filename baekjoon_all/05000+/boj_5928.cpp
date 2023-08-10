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

    int d, h, m;
    cin >> d >> h >> m;

    int s = (11 * 24 + 11) * 60 + 11;
    int e = (d * 24 + h) * 60 + m;

    if (s > e) {
        cout << -1 << '\n';
    }
    else {
        cout << e - s << '\n';
    }

    return 0;
}
