// Solve 2023-09-03

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

    for (int ti = 1; ti <= t; ti++) {
        int tri[3];

        for (int i = 0; i < 3; i++) {
            cin >> tri[i];
        }

        sort(tri, tri + 3);

        if (tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2]) {
            cout << "Case #" << ti << ": YES\n";
        }
        else {
            cout << "Case #" << ti << ": NO\n";
        }
    }

    return 0;
}
