// Solve 2023-01-07
// Update 2023-03-03

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

    int t10;
    cin >> t10;

    string t9;
    while (t10 > 0) {
        char ch = '0' + t10 % 9;
        t9 = ch + t9;
        t10 /= 9;
    }
    cout << t9 << '\n';

    return 0;
}