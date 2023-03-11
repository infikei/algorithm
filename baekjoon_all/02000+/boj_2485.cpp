// Solve 2023-03-10

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int calc_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return calc_gcd(b, a % b);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x0, x1;
    cin >> x0 >> x1;
    int x_gcd = abs(x1 - x0);
    int x_min = min(x0, x1);
    int x_max = max(x0, x1);

    for (int i = 2; i < n; i++) {
        cin >> x1;
        x_gcd = calc_gcd(abs(x1 - x0), x_gcd);
        x_min = min(x_min, x1);
        x_max = max(x_max, x1);
    }
    cout << (x_max - x_min) / x_gcd + 1 - n << '\n';

    return 0;
}