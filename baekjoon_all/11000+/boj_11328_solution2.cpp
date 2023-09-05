// Solve 2022-12-01
// Update 2023-09-05

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
        string s, s2;
        cin >> s >> s2;

        sort(s.begin(), s.end());
        sort(s2.begin(), s2.end());

        if (s == s2) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
