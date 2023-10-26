// Solve 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 0;

    for (int c = (n - 1) / 2; c * 3 >= n; c--) {
        for (int b = c; b >= 1; b--) {
            int a = n - c - b;

            if (a > b) break;

            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
