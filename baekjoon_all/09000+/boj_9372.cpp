// Solve 2023-02-18
// Update 2023-12-13

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
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
        }

        cout << n - 1 << '\n';
    }

    return 0;
}
