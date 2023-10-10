// Solve 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n1, k1, n2, k2;
    cin >> n1 >> k1 >> n2 >> k2;

    int ans = n1 * k1 + n2 * k2;

    cout << ans << '\n';

    return 0;
}
