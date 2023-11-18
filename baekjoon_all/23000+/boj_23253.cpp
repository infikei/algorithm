// Solve 2023-11-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    bool ans = true;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int x;
        cin >> x;

        for (int ki = 1; ki < k; ki++) {
            int nx;
            cin >> nx;

            if (x < nx) ans = false;

            x = nx;
        }
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
