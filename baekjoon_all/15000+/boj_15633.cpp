// Solve 2023-11-15

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

    int ans = 0;

    for (int i = 1, ie = sqrt(n); i <= ie; i++) {
        if (n % i != 0) continue;

        int j = n / i;

        if (i == j) ans += i;
        else ans += i + j;
    }

    cout << ans * 5 - 24 << '\n';

    return 0;
}
