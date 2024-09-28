// Solve 2024-09-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, a, b;
    cin >> n >> a >> b;

    int one_cnt = (a + b <= n ? a + b : n * 2 - a - b);
    int ans = 0;

    for (int i = n - one_cnt; i < n; i++) {
        ans |= (1 << i);
    }

    cout << ans << '\n';

    return 0;
}
