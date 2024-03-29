// Solve 2022-11-13
// Update 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int c;
    cin >> c;

    int cnt = 0;

    while (true) {
        cnt++;

        if (c == 1) break;

        if (c % 2 == 0) {
            c /= 2;
        }
        else {
            c *= 3;
            c += 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}
