// Solve 2023-12-26

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
        int d, n, s, p;
        cin >> d >> n >> s >> p;

        int ss = n * s;
        int pp = n * p + d;

        if (ss > pp) {
            cout << "parallelize\n";
        }
        else if (ss < pp) {
            cout << "do not parallelize\n";
        }
        else {
            cout << "does not matter\n";
        }
    }

    return 0;
}
