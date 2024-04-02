// Solve 2022-07-09
// Update 2024-04-02

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

    ll fibonacci[91] = { 0, 1 };

    for (int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }

    cout << fibonacci[n] << '\n';

    return 0;
}
