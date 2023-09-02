// Solve 2022-06-07
// Update 2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    if (k > n / 2) {
        k = n - k;
    }

    int ans = 1, j = n;

    for (int i = 1; i <= k; i++) {
        ans *= j;
        ans /= i;
        j--;
    }

    cout << ans << '\n';

    return 0;
}
