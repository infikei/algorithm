// Solve 2022-12-21
// Update 2024-03-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int a[200000];
int b[200000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n, greater<int>());
    sort(b, b + m);

    ll ans = 0;

    for (int i = 0; i < min(n, m); i++) {
        if (a[i] <= b[i]) break;

        ans += a[i] - b[i];
    }

    cout << ans << '\n';

    return 0;
}
