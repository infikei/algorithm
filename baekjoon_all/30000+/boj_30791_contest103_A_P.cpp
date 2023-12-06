// Solve 2023-12-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int vote16;
    cin >> vote16;

    int ans = 0;

    for (int i = 0; i < 4; i++) {
        int vote;
        cin >> vote;

        if (vote16 - vote <= 1000) ans++;
    }

    cout << ans << '\n';

    return 0;
}
