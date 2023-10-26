// Solve 2022-09-02
// Update 2023-10-25

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

        if (ti >= 2) cout << '\n';

        cout << "Scenario #" << ti << ":\n";

        if (tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
