// Solve 2023-11-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int stat_sum = 0;

    for (int i = 0; i < 4; i++) {
        int stat;
        cin >> stat;

        stat_sum += stat;
    }

    int n;
    cin >> n;

    int ans = n * 4 - stat_sum;

    if (ans < 0) ans = 0;

    cout << ans << '\n';

    return 0;
}
