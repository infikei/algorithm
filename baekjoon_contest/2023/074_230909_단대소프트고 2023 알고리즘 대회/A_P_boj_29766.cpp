// Solve 2023-09-09
// Update 2023-12-26

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

    int cnt = 0;

    for (int i = 0, ie = SIZE(s) - 3; i < ie; i++) {
        if (s.substr(i, 4) == "DKSH") {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
