// Solve 2022-07-23
// Update 2023-09-05

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

    int p[1000];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += p[i] * (n - i);
    }

    cout << ans << '\n';

    return 0;
}
