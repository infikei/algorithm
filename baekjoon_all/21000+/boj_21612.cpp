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

    int b;
    cin >> b;

    int p = b * 5 - 400;

    cout << p << '\n';

    if (p < 100) cout << 1 << '\n';
    else if (p > 100) cout << -1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
