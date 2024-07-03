// Solve 2022-12-24
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;

    if (a * k + b == c * k + d) {
        cout << "Yes " << a * k + b << '\n';
    }
    else {
        cout << "No\n";
    }

    return 0;
}
