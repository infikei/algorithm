// Solve 2023-08-22
// Update 2023-08-28

// 백준 같은 문제 : 20352번 = 21335번

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

int main() {
    FASTIO;

    ll a;
    cin >> a;

    SETPRECISION(9);

    cout << sqrt(a * PI * 4) << '\n';

    return 0;
}
