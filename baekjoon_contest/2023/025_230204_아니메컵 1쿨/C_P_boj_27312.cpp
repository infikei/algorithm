// Solve 2023-02-04
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

    int m, n, q;
    cin >> m >> n >> q;

    int a[1001], ans[1001];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cout << "? " << i << ' ' << i << endl;
        cin >> ans[i];

        if (++ans[i] > a[i]) {
            ans[i] = 1;
        }
    }

    for (int i = m + 1; i <= n; i++) {
        ans[i] = 1;
    }

    cout << '!';

    for (int i = 1; i <= n; i++) {
        cout << ' ' << ans[i];
    }

    cout << endl;

    return 0;
}
