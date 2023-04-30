// Solve 2022-11-08
// Update 2023-04-30

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

    ull s;
    cin >> s;

    ull n = sqrt(s * 2);
    while (true) {
        if (n * (n + 1) / 2 > s) {
            n--;
            break;
        }
        n++;
    }

    cout << n << '\n';

    return 0;
}
