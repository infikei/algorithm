// Solve 2023-02-11
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    bool check_pages[101] = { false };

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        check_pages[x] = true;
    }

    int ans = 0;
    int prev_idx = -100;

    for (int i = 1; i <= n; i++) {
        if (check_pages[i]) continue;

        ans += min(7, (i - prev_idx) * 2);
        prev_idx = i;
    }

    cout << ans << '\n';

    return 0;
}
