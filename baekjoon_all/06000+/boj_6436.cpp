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
        int s;
        cin >> s;

        if (s == 0) break;

        s = round(s * 0.75);
        int ans = (s + 1860000 - 1) / 1860000;

        if (ti >= 2) cout << '\n';

        cout << "File #" << ti++ << "\nJohn needs " << ans << " floppies.\n";
    }

    return 0;
}
