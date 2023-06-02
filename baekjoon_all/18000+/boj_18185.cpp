// Solve 2023-06-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int a[10002];

int main() {
    FASTIO;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i + 1] > a[i + 2]) {
            int x5 = min(a[i], a[i + 1] - a[i + 2]);
            a[i] -= x5;
            a[i + 1] -= x5;
            ans += x5 * 5;
        }

        int x7 = min(a[i], min(a[i + 1], a[i + 2]));
        a[i] -= x7;
        a[i + 1] -= x7;
        a[i + 2] -= x7;
        ans += x7 * 7;

        ans += a[i] * 3;
    }

    cout << ans << '\n';

    return 0;
}
