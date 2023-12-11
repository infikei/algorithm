// Solve 2023-12-11

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
        int n;
        string s;
        cin >> n >> s;

        int x = 0;
        int y = 0;

        for (char c : s) {
            if (c == 'E') x++;
            else if (c == 'W') x--;
            else if (c == 'N') y++;
            else y--;
        }

        cout << abs(x) + abs(y) << '\n';
    }

    return 0;
}
