// Solve 2022-10-25
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    if (t % 10 == 0) {
        int a = t / 300;
        int b = t % 300 / 60;
        int c = t % 60 / 10;

        cout << a << ' ' << b << ' ' << c << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
