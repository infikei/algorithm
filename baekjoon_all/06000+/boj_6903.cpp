// Solve 2023-11-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t, s, h;
    cin >> t >> s >> h;

    string sep(s, ' ');
    string row = "*" + sep + "*" + sep + "*";

    for (int i = 0; i < t; i++) {
        cout << row << '\n';
    }

    row.assign(s * 2 + 3, '*');

    cout << row << '\n';

    row = " " + sep + "*";

    for (int i = 0; i < h; i++) {
        cout << row << '\n';
    }

    return 0;
}
