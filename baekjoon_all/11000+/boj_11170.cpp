// Solve 2023-01-09
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int count_zero(int k) {
    if (k < 0) return 0;

    int res = 0;

    res += k / 10 + 1;
    res += max(0, (k / 100 - 1) * 10 + min(10, k % 100 + 1));
    res += max(0, (k / 1000 - 1) * 100 + min(100, k % 1000 + 1));
    res += max(0, (k / 10000 - 1) * 1000 + min(1000, k % 10000 + 1));
    res += max(0, (k / 100000 - 1) * 10000 + min(10000, k % 100000 + 1));
    res += max(0, (k / 1000000 - 1) * 100000 + min(100000, k % 1000000 + 1));

    return res;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;

        int ans = count_zero(m) - count_zero(n - 1);

        cout << ans << '\n';
    }

    return 0;
}
