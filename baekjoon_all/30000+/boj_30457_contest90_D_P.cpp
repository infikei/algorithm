// Solve 2023-11-05
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

    int n;
    cin >> n;

    int cnt[1001] = { 0 };
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (++cnt[x] <= 2) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
