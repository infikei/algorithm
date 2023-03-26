// Solve 2023-03-25

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

    int x0, n;
    cin >> x0 >> n;

    int x = x0;
    for (int i = 0; i < n; i++) {
        if (x & 1) {
            x <<= 1;
        }
        else {
            x >>= 1;
        }
        x ^= 6;
    }
    cout << x << '\n';

    return 0;
}
