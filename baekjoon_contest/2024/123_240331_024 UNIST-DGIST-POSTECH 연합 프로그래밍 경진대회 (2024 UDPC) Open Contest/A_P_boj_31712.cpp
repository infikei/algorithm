// Solve 2024-03-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int c[3], d[3];

    for (int i = 0; i < 3; i++) {
        cin >> c[i] >> d[i];
    }

    int h;
    cin >> h;

    int cur = 0;

    while (true) {
        for (int i = 0; i < 3; i++) {
            if (cur % c[i] == 0) {
                h -= d[i];
            }
        }

        if (h <= 0) break;

        cur++;
    }

    cout << cur << '\n';

    return 0;
}
