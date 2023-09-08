// Solve 2023-09-07

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

    vector<ll> dist2;

    for (int i = 0; i < n; i++) {
        int point_cnt;
        cin >> point_cnt;

        ll now_dist2 = 0;

        for (int j = 0; j < point_cnt; j++) {
            ll x, y;
            cin >> x >> y;

            now_dist2 = max(now_dist2, x * x + y * y);
        }

        dist2.push_back(now_dist2);
    }

    sort(dist2.begin(), dist2.end());

    SETPRECISION(2);

    cout << (double)dist2[k - 1] << '\n';

    return 0;
}
