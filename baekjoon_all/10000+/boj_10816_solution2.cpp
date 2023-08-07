// Solve 2022-06-03
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int card[500000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    sort(card, card + n);

    int m, x;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x;

        auto lo = lower_bound(card, card + n, x);
        auto up = upper_bound(card, card + n, x);
        int ans = up - lo;

        cout << ans << ' ';
    }

    cout << '\n';

    return 0;
}
