// Solve 2023-05-02

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

    ull n;
    cin >> n;

    ull left = 0, right = 3037000500;
    if (n == 0) {
        right = 0;
    }
    while (left + 1 < right) {
        ull mid = (left + right) >> 1;
        ull val = mid * mid;

        if (val >= n) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    cout << right << '\n';

    return 0;
}
