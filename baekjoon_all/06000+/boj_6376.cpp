// Solve 2023-01-02
// Update 2023-03-07

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

    cout << "n e\n";
    cout << "- -----------\n";

    double e = 0;
    int fac = 1;
    for (int i = 0; i < 10; i++) {
        if (i > 0) {
            fac *= i;
        }
        e += 1 / (double)fac;

        if (i > 2) {
            SETPRECISION(9);
        }
        cout << i << ' ' << e << '\n';
    }

    return 0;
}