// Solve 2024-05-01

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

    int cur = 1;

    for (char c : s) {
        if (c == 'A') {
            if (cur <= 2) {
                cur = 3 - cur;
            }
        }
        else if (c == 'B') {
            if (cur >= 2) {
                cur = 5 - cur;
            }
        }
        else {
            cur = 4 - cur;
        }
    }

    cout << cur << '\n';

    return 0;
}
