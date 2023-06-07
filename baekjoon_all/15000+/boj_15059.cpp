// Solve 2023-06-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int r;
        cin >> r;

        if (r > a[i]) {
            ans += r - a[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
