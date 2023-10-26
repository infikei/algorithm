// Solve 2022-11-07
// Update 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string bowls;
    cin >> bowls;

    int ans = 10;

    for (int i = 1; i < SIZE(bowls); i++) {
        if (bowls[i] == bowls[i - 1]) ans += 5;
        else ans += 10;
    }

    cout << ans << '\n';

    return 0;
}
