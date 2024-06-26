// Solve 2024-04-23

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
        int j = n / i;

        ans += (j - i + 1);
    }

    cout << ans << '\n';

    return 0;
}
