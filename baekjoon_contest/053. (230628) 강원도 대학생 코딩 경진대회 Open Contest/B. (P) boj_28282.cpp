// Solve 2023-06-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll cnt[10001][2];

int main() {
    FASTIO;

    int x, k;
    cin >> x >> k;

    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        cnt[a][0]++;
    }
    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        cnt[a][1]++;
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += cnt[i][0] * (x - cnt[i][1]);
    }
    cout << ans << '\n';

    return 0;
}
