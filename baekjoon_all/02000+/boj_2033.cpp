// Solve 2024-04-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n > 10) {
        n = (n + 5) / 10 * 10;
    }

    if (n > 100) {
        n = (n + 50) / 100 * 100;
    }

    if (n > 1000) {
        n = (n + 500) / 1000 * 1000;
    }

    if (n > 10000) {
        n = (n + 5000) / 10000 * 10000;
    }

    if (n > 100000) {
        n = (n + 50000) / 100000 * 100000;
    }

    if (n > 1000000) {
        n = (n + 500000) / 1000000 * 1000000;
    }

    if (n > 10000000) {
        n = (n + 5000000) / 10000000 * 10000000;
    }

    if (n > 100000000) {
        n = (n + 50000000) / 100000000 * 100000000;
    }

    cout << n << '\n';

    return 0;
}
