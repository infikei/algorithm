// Solve 2023-11-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    int ans = min(n, 9) - max(1, 10 - m) + 1;
    ans = max(ans, 0);

    if (ans == 1) {
        cout << "There is 1 way to get the sum 10.\n";
    }
    else {
        cout << "There are " << ans << " ways to get the sum 10.\n";
    }

    return 0;
}
