// Solve 2024-03-15

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

    if (n == 1) {
        cout << 1 << '\n';
    }
    else if (n == 12) {
        cout << 2 << '\n';
    }
    else if (n == 123) {
        cout << 3 << '\n';
    }
    else if (n == 1234) {
        cout << 4 << '\n';
    }
    else if (n == 12345) {
        cout << 5 << '\n';
    }
    else if (n == 123456) {
        cout << 6 << '\n';
    }
    else if (n == 1234567) {
        cout << 7 << '\n';
    }
    else if (n == 12345678) {
        cout << 8 << '\n';
    }
    else if (n == 123456789) {
        cout << 9 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
