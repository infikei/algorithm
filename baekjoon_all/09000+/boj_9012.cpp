// Solve 2022-06-05
// Update 2023-03-23

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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string parentheses;
        cin >> parentheses;
        int vps = 0;

        for (char par : parentheses) {
            if (par == '(') {
                vps++;
            }
            else {
                vps--;
                if (vps < 0) {
                    break;
                }
            }
        }

        if (vps == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
