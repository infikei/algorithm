// Solve 2023-09-10

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

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        if (n > 4500) {
            cout << "Case #" << ti << ": Round 1\n";
        }
        else if (n > 1000) {
            cout << "Case #" << ti << ": Round 2\n";
        }
        else if (n > 25) {
            cout << "Case #" << ti << ": Round 3\n";
        }
        else {
            cout << "Case #" << ti << ": World Finals\n";
        }
    }

    return 0;
}
