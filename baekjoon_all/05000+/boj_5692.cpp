// Solve 2023-04-03

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

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int iter = 1, fac = 1, ans = 0;
        while (n > 0) {
            fac *= iter;
            ans += (n % 10) * fac;
            n /= 10;
            iter++;
        }

        cout << ans << '\n';
    }

    return 0;
}
