// Solve 2023-03-10
// Update 2023-08-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x0, x;
    cin >> x0 >> x;
    int x_gcd = abs(x - x0);
    int x_min = min(x0, x);
    int x_max = max(x0, x);

    for (int i = 2; i < n; i++) {
        cin >> x;
        x_gcd = calc_gcd(abs(x - x0), x_gcd);
        x_min = min(x_min, x);
        x_max = max(x_max, x);
    }

    cout << (x_max - x_min) / x_gcd + 1 - n << '\n';

    return 0;
}
