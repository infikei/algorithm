// Solve 2022-09-02
// Update 2023-03-15

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

    int d, h_ratio, w_ratio;
    cin >> d >> h_ratio >> w_ratio;

    double d_ratio = sqrt(h_ratio * h_ratio + w_ratio * w_ratio);
    int h = d * h_ratio / d_ratio;
    int w = d * w_ratio / d_ratio;

    cout << h << ' ' << w << '\n';

    return 0;
}
