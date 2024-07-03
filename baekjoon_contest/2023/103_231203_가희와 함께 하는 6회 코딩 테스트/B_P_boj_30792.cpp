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

    int n, v0;
    cin >> n >> v0;

    int ans = 1;

    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;

        if (v > v0) ans++;
    }

    cout << ans << '\n';

    return 0;
}
