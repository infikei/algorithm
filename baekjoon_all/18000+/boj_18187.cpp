// Solve 2023-09-06

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

    if (n % 3 == 0) {
        ans = n * (n / 3 + 1) + 1; // a_3n = 3n^2 + 3n + 1
    }
    else if (n % 3 == 1) {
        int n3 = n / 3;
        ans = (n3 + 1) * (3 * n3 + 2); // a_(3n+1) = 3n^2 + 5n + 2
    }
    else {
        int n3 = n / 3;
        ans = (n3 + 1) * (3 * n3 + 4); // a_(3n+2) = 3n^2 + 7n + 4
    }

    cout << ans << '\n';

    return 0;
}
