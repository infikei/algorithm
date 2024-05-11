// Solve 2024-05-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int c[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n, greater<int>());

    ll ans = 0;

    for (int i = 0; i < n; i += 3) {
        ans += c[i];

        if (i + 1 < n) ans += c[i + 1];
    }

    cout << ans << '\n';

    return 0;
}
