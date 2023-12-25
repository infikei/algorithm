// Solve 2023-09-23
// Update 2023-12-25

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

    for (int ki = 0; ki < k; ki++) {
        int g;
        cin >> g;

        int p = g * 100 / n;
        int ans = 0;

        if (p <= 4) ans = 1;
        else if (p <= 11) ans = 2;
        else if (p <= 23) ans = 3;
        else if (p <= 40) ans = 4;
        else if (p <= 60) ans = 5;
        else if (p <= 77) ans = 6;
        else if (p <= 89) ans = 7;
        else if (p <= 96) ans = 8;
        else ans = 9;

        cout << ans << ' ';
    }

    cout << '\n';

    return 0;
}
