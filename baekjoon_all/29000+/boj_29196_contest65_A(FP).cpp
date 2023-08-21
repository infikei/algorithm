// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double k;
    cin >> k;

    int p = k * 1e8;
    int q = 1e8;

    cout << "YES\n" << p << ' ' << q << '\n';

    return 0;
}
