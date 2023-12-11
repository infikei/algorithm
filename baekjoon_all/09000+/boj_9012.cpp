// Solve 2022-06-05
// Update 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

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
                if (--vps < 0) break;
            }
        }

        cout << (vps == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
