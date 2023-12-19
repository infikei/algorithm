// Solve 2022-08-14
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<string> serolines(15);

    for (int row = 0; row < 5; row++) {
        string line;
        cin >> line;

        for (int col = 0, col_end = SIZE(line); col < col_end; col++) {
            serolines[col].push_back(line[col]);
        }
    }

    for (string &seroline : serolines) {
        cout << seroline;
    }

    cout << '\n';

    return 0;
}
