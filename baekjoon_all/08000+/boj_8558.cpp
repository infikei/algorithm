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

    int n;
    cin >> n;

    if (n <= 1) cout << 1 << '\n';
    else if (n == 2) cout << 2 << '\n';
    else if (n == 3) cout << 6 << '\n';
    else if (n == 4) cout << 4 << '\n';
    else cout << 0 << '\n';

    return 0;
}
