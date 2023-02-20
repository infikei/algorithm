// Solve 2022-06-06
// Update 2023-02-21

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        cin >> a >> b;

        int ans = 1;
        a = (a - 1) % 10 + 1;
        b = (b - 1) % 4 + 1;
        while (b--) {
            ans *= a;
        }
        cout << (ans - 1) % 10 + 1 << '\n';
    }

    return 0;
}