// Solve 2022-11-24
// Update 2023-10-08

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
        int r;
        cin >> r;

        if (r == 0) break;

        int w, l;
        cin >> w >> l;

        cout << "Pizza " << ti++;

        if (r * r * 4 >= w * w + l * l) {
            cout << " fits on the table.\n";
        }
        else {
            cout << " does not fit on the table.\n";
        }
    }

    return 0;
}
