// Solve 2023-05-21

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

    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;
    if (n > 1) {
        if (x == 1 || x == n) {
            if (y == 1 || y == n) {
                ans = 2;
            }
            else {
                ans = 3;
            }
        }
        else if (y == 1 || y == n) {
            ans = 3;
        }
        else {
            ans = 4;
        }
    }
    cout << ans << '\n';

    return 0;
}
