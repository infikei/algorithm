// Solve 2022-07-23
// Update 2023-09-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string line;
    cin >> line;

    int ans = 0, tmp = 0, plus_minus = 0;

    for (int i = 0, ie = SIZE(line); i < ie; i++) {
        char ch = line[i];

        if (ch == '+' || ch == '-') {
            if (plus_minus == 0) ans += tmp;
            else ans -= tmp;

            if (ch == '-') plus_minus = 1;

            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += ch - '0';
        }
    }

    if (plus_minus == 0) ans += tmp;
    else ans -= tmp;

    cout << ans << '\n';

    return 0;
}
