// Solve 2023-10-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ans[6];

    for (int i = 0; i < 6; i++) {
        string s;
        getline(cin, s);

        ans[i] = SIZE(s);

        if (s.back() == ' ') ans[i]--;
    }

    cout << "Latitude " << ans[0] << ':' << ans[1] << ':' << ans[2] << '\n';
    cout << "Longitude " << ans[3] << ':' << ans[4] << ':' << ans[5] << '\n';

    return 0;
}
