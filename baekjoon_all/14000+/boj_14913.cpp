// Solve 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, d, k;
    cin >> a >> d >> k;

    if ((k - a) % d != 0) {
        cout << "X\n";
    }
    else {
        int ans = (k - a) / d + 1;

        if (ans >= 1) {
            cout << ans << '\n';
        }
        else {
            cout << "X\n";
        }
    }

    return 0;
}
