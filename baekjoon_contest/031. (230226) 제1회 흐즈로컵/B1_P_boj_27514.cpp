// Solve 2023-02-26

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

    int n;
    cin >> n;

    ull now = 0;
    for (int i = 0; i < n; i++) {
        ull x;
        cin >> x;
        if (x == 0) continue;

        while ((now & x) != 0) {
            now ^= x;
            x <<= 1;
        }
        now ^= x;
    }

    ull tmp = 1;
    tmp <<= 62;
    while ((now & tmp) == 0) {
        tmp >>= 1;
    }
    cout << (now & tmp) << '\n';

    return 0;
}