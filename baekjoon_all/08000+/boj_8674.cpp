// Solve 2023-09-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll a, b;
    cin >> a >> b;

    if (a % 2 == 0 || b % 2 == 0) {
        cout << 0 << '\n';
    }
    else {
        cout << min(a, b) << '\n';
    }

    return 0;
}
