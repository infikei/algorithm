// Solve 2023-01-09
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int p, q;
    cin >> p >> q;

    if (p <= 50 && q <= 10) cout << "White\n";
    else if (q > 30) cout << "Red\n";
    else cout << "Yellow\n";

    return 0;
}
