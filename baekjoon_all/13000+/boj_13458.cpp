// Solve 2022-11-07
// Update 2023-07-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int a[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b, c;
    cin >> b >> c;

    ll ans = n;
    for (int i = 0; i < n; i++) {
        if (a[i] > b) {
            ans += (a[i] - b - 1) / c + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
