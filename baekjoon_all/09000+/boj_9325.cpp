// Solve 2022-10-01
// Update 2023-12-12

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
        int s, n;
        cin >> s >> n;

        for (int i = 0; i < n; i++) {
            int q, p;
            cin >> q >> p;

            s += q * p;
        }

        cout << s << '\n';
    }

    return 0;
}
