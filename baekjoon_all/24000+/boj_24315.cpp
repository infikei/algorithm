// Solve 2023-02-22
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a1, a0, c1, c2, n0;
    cin >> a1 >> a0 >> c1 >> c2 >> n0;

    if (c1 <= a1 && a1 <= c2 && (c1 - a1) * n0 <= a0 && a0 <= (c2 - a1) * n0) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
