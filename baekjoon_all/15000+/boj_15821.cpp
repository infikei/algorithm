// Solve 2023-09-07
// Update 2023-11-21

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

    vector<ll> dist2(n);

    for (int ni = 0; ni < n; ni++) {
        int points_cnt;
        cin >> points_cnt;

        ll now_dist2 = 0;

        for (int i = 0; i < points_cnt; i++) {
            ll x, y;
            cin >> x >> y;

            now_dist2 = max(now_dist2, x * x + y * y);
        }

        dist2[ni] = now_dist2;
    }

    sort(dist2.begin(), dist2.end());

    cout << dist2[k - 1] << ".00\n";

    return 0;
}
