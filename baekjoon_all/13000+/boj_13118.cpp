// Solve 2022-11-03
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int people[5];

    for (int i = 1; i <= 4; i++) {
        cin >> people[i];
    }

    int x, y, r;
    cin >> x >> y >> r;

    int ans = 0;

    for (int i = 1; i <= 4; i++) {
        if (people[i] == x) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
