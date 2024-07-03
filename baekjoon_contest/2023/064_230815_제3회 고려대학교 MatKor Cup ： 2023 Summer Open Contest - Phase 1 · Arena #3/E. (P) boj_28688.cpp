// Solve 2023-08-15

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
        ll n, m;
        cin >> n >> m;

        if (n <= 2 || m <= 2 || n % 2 == 1 && m % 2 == 1) cout << "First\n";
        else cout << "Second\n";
    }

    return 0;
}
