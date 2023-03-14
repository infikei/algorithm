// Solve 2022-06-03
// Update 2023-03-14

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

const double PI = acos(-1);

int main() {
    FASTIO;

    double r;
    cin >> r;
    r *= r;

    SETPRECISION(6);
    cout << r * PI << '\n';
    cout << r * 2 << '\n';

    return 0;
}
