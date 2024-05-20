// Solve 2024-05-19
// Update 2024-05-20

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

    int cards[1000];

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    sort(cards, cards + n, greater<int>());

    int ans = 0;

    for (int i = 0; i < min(m, (n + 1) / 2); i++) {
        if (cards[i] <= 0) break;

        ans += cards[i];
    }

    cout << ans << '\n';

    return 0;
}
