// Solve 2023-12-02

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

int calc_lcm(int a, int b) {
    return a / calc_gcd(a, b) * b;
}

int main() {
    FASTIO;

    int x, y;
    cin >> x >> y;

    int lcm = calc_lcm(x, y);
    int dx = lcm / x;
    int dy = lcm / y;

    vector<int> ans(lcm + 1, 0);

    for (int i = dx; i <= lcm; i += dx) {
        ans[i] = 1;
    }

    for (int i = dy; i <= lcm; i += dy) {
        ans[i] += 2;
    }

    for (int i = 1; i <= lcm; i++) {
        if (ans[i] != 0) {
            cout << ans[i];
        }
    }

    cout << '\n';

    return 0;
}
