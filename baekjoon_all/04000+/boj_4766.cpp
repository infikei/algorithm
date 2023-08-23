// Solve 2022-11-23
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(2);

    double cur, prev;
    cin >> prev;

    while (true) {
        cin >> cur;
        if (cur == 999) break;

        cout << cur - prev << '\n';

        prev = cur;
    }

    return 0;
}
