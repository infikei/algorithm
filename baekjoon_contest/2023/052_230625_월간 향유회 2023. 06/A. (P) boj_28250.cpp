// Solve 2023-06-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll cnt[3];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 2) x = 2;
        cnt[x]++;
    }

    ll ans = (cnt[0] * (cnt[0] - 1)) >> 1;
    ans += cnt[0] * cnt[2];
    ans += (cnt[0] * cnt[1]) << 1;

    cout << ans << '\n';

    return 0;
}
