// Solve 2023-10-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ti = 1;

    while (true) {
        int p, s;
        cin >> p >> s;

        if (p == 0) break;

        if (ti >= 2) cout << '\n';

        cout << "Hole #" << ti++ << '\n';

        if (s == 1) cout << "Hole-in-one.\n";
        else if (s == p - 3) cout << "Double eagle.\n";
        else if (s == p - 2) cout << "Eagle.\n";
        else if (s == p - 1) cout << "Birdie.\n";
        else if (s == p) cout << "Par.\n";
        else if (s == p + 1) cout << "Bogey.\n";
        else cout << "Double Bogey.\n";
    }

    return 0;
}
