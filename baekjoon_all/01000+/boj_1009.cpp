// Solve 2022-06-06
// Update 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        cin >> a >> b;

        a = (a - 1) % 10 + 1;
        b = (b - 1) % 4 + 1;

        int ans = 1;

        while (b--) {
            ans *= a;
        }

        cout << (ans - 1) % 10 + 1 << '\n';
    }

    return 0;
}
