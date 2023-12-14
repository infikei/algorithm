// Solve 2022-11-09
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int f[46] = { 0, 1, 1 };

    for (int i = 3; i < 46; i++) {
        f[i] = f[i - 2] + f[i - 1];
    }

    int n;
    cin >> n;

    cout << f[n - 1] << ' ' << f[n] << '\n';

    return 0;
}
