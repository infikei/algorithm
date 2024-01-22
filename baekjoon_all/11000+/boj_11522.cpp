// Solve 2024-01-21

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
        int k, n;
        cin >> k >> n;

        int n2 = n * n;
        int n2_n = n2 + n;

        cout << k << ' ' << n2_n / 2 << ' ' << n2 << ' ' << n2_n << '\n';
    }

    return 0;
}
