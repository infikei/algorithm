// Solve 2023-09-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x, k;
    cin >> x >> k;

    if (7000 * k <= 1000 * x) {
        cout << 7000 * k << '\n';
    }
    else if (3500 * k <= 1000 * x) {
        cout << 3500 * k << '\n';
    }
    else if (1750 * k <= 1000 * x) {
        cout << 1750 * k << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
