// Solve 2022-10-12
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int x;
        cin >> x;

        for (int i = 1; i < n; i++) {
            int y;
            cin >> y;

            if (x == y) continue;

            cout << x << ' ';
            x = y;
        }

        cout << x << " $\n";
    }

    return 0;
}
