// Solve 2023-04-30
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int nop = 0;

    for (int i = 0, ie = SIZE(s); i < ie; i++) {
        if (isupper(s[i])) {
            int r = (i + nop) % 4;

            if (r > 0) nop += 4 - r;
        }
    }

    cout << nop << '\n';

    return 0;
}
