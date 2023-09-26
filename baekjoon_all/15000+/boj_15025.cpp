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

    int l, r;
    cin >> l >> r;

    if (l + r == 0) cout << "Not a moose\n";
    else if (l == r) cout << "Even " << l + r << '\n';
    else cout << "Odd " << max(l, r) * 2 << '\n';

    return 0;
}
