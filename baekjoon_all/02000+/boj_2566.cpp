// Solve 2022-09-13
// Update 2023-02-26

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

    int max_idx = 0, max_val = 0;
    for (int i = 0; i < 81; i++) {
        int x;
        cin >> x;
        if (x > max_val) {
            max_val = x;
            max_idx = i;
        }
    }

    cout << max_val << '\n';
    cout << max_idx / 9 + 1 << ' ' << max_idx % 9 + 1 << '\n';

    return 0;
}