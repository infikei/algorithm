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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans1 = a * d + b * c;
    int ans2 = b * d;

    int gcd = calc_gcd(ans1, ans2);
    cout << ans1 / gcd << ' ' << ans2 / gcd << '\n';

    return 0;
}