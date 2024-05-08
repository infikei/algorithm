// Solve 2024-05-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    a += b;

    if (a < 10) {
        cout << 1 << '\n';
    }
    else if (a < 100) {
        cout << 2 << '\n';
    }
    else {
        cout << 3 << '\n';
    }

    return 0;
}
