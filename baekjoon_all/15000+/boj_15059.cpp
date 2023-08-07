// Solve 2023-06-07
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

    int meal[3];

    for (int i = 0; i < 3; i++) {
        cin >> meal[i];
    }

    int ans = 0;

    for (int i = 0; i < 3; i++) {
        int req;
        cin >> req;

        if (req > meal[i]) {
            ans += req - meal[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
