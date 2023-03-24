// Solve 2022-09-18
// Update 2023-03-24

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

    ll t[36] = { 0 };
    t[0] = 1;
    for (int i = 1; i <= n; i++) {
        int i2 = i / 2;
        for (int j = 0; j < i2; j++) {
            t[i] += t[j] * t[i - 1 - j] * 2;
        }
        if (i % 2 == 1) {
            t[i] += t[i2] * t[i2];
        }
    }

    cout << t[n] << '\n';

    return 0;
}
