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

    int a, b, c;
    cin >> a >> b >> c;

    int ans = min({ 4 * a + 2 * b, 2 * a + 2 * c, 2 * b + 4 * c });

    cout << ans << '\n';

    return 0;
}
